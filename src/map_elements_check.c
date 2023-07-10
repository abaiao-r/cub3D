/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 20:05:29 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		process_element(map, elements_var, elements_data);
		elements_var->i++;
	}
	if (elements_var->count_elements != elements_var->num_elements)
	{
		map->check_elem = 1;
		free(elements_var);
		return (0);
	}
	free(elements_var);
	return (1);
}
