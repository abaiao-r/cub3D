/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/09 14:38:09 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	int		i;
	char	*temp;

	i = 0;
	while (i < map->elements_end + 1)
	{
		temp = map->desc_file[i];
		ft_skip_whitespace(&temp);
		if (!is_valid_identifier(temp))
		{
			map->check_elem = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

static void	init_elements_data(t_elements_data *elements_data)
{
	elements_data->elements[0] = "NO";
	elements_data->elements[1] = "SO";
	elements_data->elements[2] = "WE";
	elements_data->elements[3] = "EA";
	elements_data->elements[4] = "F";
	elements_data->elements[5] = "C";
	elements_data->num_elements = sizeof(elements_data->elements)
		/ sizeof(elements_data->elements[0]);
	elements_data->count_elements = 0;
}

static void	process_element(t_map *map, t_elements_data *elements_data, int i)
{
	int	j;

	elements_data->element = elements_data->elements[i];
	elements_data->element_len = ft_strlen(elements_data->element);
	j = 0;
	while (j < map->lin)
	{
		elements_data->temp = map->desc_file[j];
		ft_skip_whitespace(&elements_data->temp);
		if (ft_strncmp(elements_data->temp, elements_data->element,
				elements_data->element_len) == 0
			&& ft_isspace(elements_data->temp[elements_data->element_len]))
		{
			elements_data->count_elements++;
			if (elements_data->count_elements == elements_data->num_elements)
				map->elements_end = j;
		}
		j++;
	}
}

int	check_elements(t_map *map)
{
	t_elements_data	*elements_data;
	int				i;

	elements_data = calloc(1, sizeof(t_elements_data));
	init_elements_data(elements_data);
	i = 0;
	while (i < elements_data->num_elements)
	{
		process_element(map, elements_data, i);
		i++;
	}
	if (elements_data->count_elements != elements_data->num_elements)
	{
		map->check_elem = 1;
		return (0);
	}
	printf(" Elements OK\n"); //debug message
	return (1);
}

/* int	check_elements(t_map *map)
{
	char	*elements[6];
	int		i;
	int		j;
	int		num_elements;
	int		count_elements;
	char	*element;
	char	*temp;
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
			temp = map->desc_file[j];
			ft_skip_whitespace(&temp);
			if (ft_strncmp(temp, element, element_len) == 0
				&& ft_isspace(temp[element_len]))
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
		map->check_elem = 1;
		return (0);
	}
	printf("OK\n"); //debug message
	return (1);
} */
