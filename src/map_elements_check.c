/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/11 12:23:23 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
