/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/11 15:06:41 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  free_map_elements: frees the allocated memory.
 *  @param elements_data: elements_data structure.
 *  @param elements_var: elements_var structure.
 *  @param map: map structure.
 */
static void	free_map_elements(t_elements_data *elements_data,
		t_elements_var *elements_var, t_map *map)
{
	if (elements_data->no_texture)
		free(elements_data->no_texture);
	if (elements_data->so_texture)
		free(elements_data->so_texture);
	if (elements_data->we_texture)
		free(elements_data->we_texture);
	if (elements_data->ea_texture)
		free(elements_data->ea_texture);
	free(elements_data);
	if (elements_var->elements)
		free(elements_var);
	map->check_elem = 1;
}

/* process_element: checks if the element is correct.
 *  It checks if the element is in the map description file.
 *  Then it checks if the path of the texture is correct.
 *  If it is not, it frees the allocated memory and returns 0.
 *  If it is, it increments the count_elements.
 *  If the count_elements is equal to the number of elements
 *  it assigns the elements_end to the map structure.
 * @param map: map structure.
 * @param elements_var: elements_var structure.
 * @param elements_data: elements_data structure.
 * @return: 1 if the element is correct, 0 if not.
 */
static int	process_element(t_map *map, t_elements_var *elements_var,
		t_elements_data *elements_data)
{
	elements_var->element = elements_var->elements[elements_var->i];
	elements_var->element_len = ft_strlen(elements_var->element);
	while (elements_var->j < map->lin)
	{
		elements_var->temp = map->desc_file[elements_var->j];
		ft_skip_whitespace(&elements_var->temp);
		if (ft_strncmp(elements_var->temp, elements_var->element,
				elements_var->element_len) == 0
			&& ft_isspace(elements_var->temp[elements_var->element_len]))
		{
			elements_var->count_elements++;
			if (check_textures_path(map, elements_var, elements_data) == 0)
				return (0);
			if (elements_var->count_elements == elements_var->num_elements)
				map->elements_end = elements_var->j;
		}
		elements_var->j++;
	}
	return (1);
}

/* init_elements_var: initializes the elements_var structure.
 *  @param elements_var: elements_var structure.
 */
static void	init_elements_var(t_elements_var *elements_var)
{
	elements_var->elements[0] = "NO";
	elements_var->elements[1] = "SO";
	elements_var->elements[2] = "WE";
	elements_var->elements[3] = "EA";
	elements_var->elements[4] = "F";
	elements_var->elements[5] = "C";
	elements_var->num_elements = sizeof(elements_var->elements)
		/ sizeof(elements_var->elements[0]);
	elements_var->count_elements = 0;
	elements_var->i = 0;
	elements_var->j = 0;
}

/*  check_elements: checks if the map elements are correct.
 *  It initializes the elements_var and elements_data structures.
 *  Then it calls process_element function. If it returns 0, it frees
 *  the allocated memory and returns 0.
 *  If it returns 1, it checks if the number of elements is correct.
 *  If it is not, it frees the allocated memory and returns 0.
 *  If it is, it assigns the elements_data structure to the map structure.
 *  Then it frees the allocated memory and returns 1.
 *  @param map: map structure.
 *  @return: 1 if the elements are correct, 0 if not.
 */
int	check_elements(t_map *map)
{
	t_elements_var	*elements_var;
	t_elements_data	*elements_data;

	elements_data = ft_calloc(1, sizeof(t_elements_data));
	elements_var = ft_calloc(1, sizeof(t_elements_var));
	init_elements_var(elements_var);
	while (elements_var->i < elements_var->num_elements)
	{
		elements_var->j = 0;
		if (process_element(map, elements_var, elements_data) == 0)
		{
			free_map_elements(elements_data, elements_var, map);
			return (0);
		}
		elements_var->i++;
	}
	if (elements_var->count_elements != elements_var->num_elements)
	{
		write(2, "Error\nNumber of elements is incorrect\n", 38);
		free_map_elements(elements_data, elements_var, map);
		return (0);
	}
	map->elements_data = elements_data;
	free(elements_var);
	return (1);
}
