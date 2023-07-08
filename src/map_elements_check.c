/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/08 19:07:29 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_elements(t_map *map)
{
	char	*elements[6];
	int		i;
	int		j;
	int		num_elements;
	int		count_elements;
	char	*element;
	int		element_len;

	elements[0] = "NO";
	elements[1] = "SO";
	elements[2] = "WE";
	elements[3] = "EA";
	elements[4] = "F";
	elements[5] = "C";
	num_elements = sizeof(elements) / sizeof(elements[0]);
	i = 0;
	count_elements = 0;
	while (i < num_elements)
	{
		element = elements[i];
		element_len = ft_strlen(element);
		j = 0;
		while (j < map->lin)
		{
			ft_skip_whitespace(&map->desc_file[j]);
			if (ft_strncmp(map->desc_file[j], element, element_len) == 0
				&& ft_isspace(map->desc_file[j][element_len]))
			{
				count_elements++;
				if (count_elements == num_elements)
					map->elements_end = j;
			}
			j++;
		}
		i++;
	}
	if (count_elements != num_elements)
	{
		printf("Error: Missing element(s)\n");
		return (0);
	}
	printf("OK\n");
	return (1);
}

int	is_valid_identifier(char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0 || ft_strncmp(str, "SO", 2) == 0)
		return (1);
	if (ft_strncmp(str, "WE", 2) == 0 || ft_strncmp(str, "EA", 2) == 0)
		return (1);
	if (ft_strncmp(str, "F", 1) == 0 || ft_strncmp(str, "C", 1) == 0)
		return (1);
	if (ft_is_input_only_whitespaces(str) == 1)
		return (1);
	return (0);
}

int	check_extra_args(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->elements_end + 1)
	{
		ft_skip_whitespace(&map->desc_file[i]);
		if (!is_valid_identifier(map->desc_file[i]))
		{
			printf("Extra arg in identifiers\n");
			return (0);
		}
		i++;
	}
	return (1);
}
