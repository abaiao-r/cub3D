/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check_utils3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:05:10 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 20:05:35 by abaiao-r         ###   ########.fr       */
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
