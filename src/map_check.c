/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:12:12 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/11 19:30:22 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*Vê se os caracteres pelos quais o mapa é composto são 
('0'- empty '1'- wall 'N','S','W','E' - player)
conta nº de players (têm que ser = 1)*/
int	check_chars(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->lin)
	{
		j = 0;
		while (map->game_map[i][j] != '\n' && map->game_map[i][j] != '\0')
		{
			if (map->game_map[i][j] == 'N' || map->game_map[i][j] == 'S'
				|| map->game_map[i][j] == 'W' || map->game_map[i][j] == 'E')
			{
				map->count_player++;
				map->player_c = j;
				map->player_l = i;
			}
			else if (map->game_map[i][j] != '1' && map->game_map[i][j] != '0')
				return (0);
			j++;
		}
	}
	return (1);
}

int	check_whitespace(char **str, int pos)
{
	while (str && str[pos])
	{
		if (!(ft_is_input_only_whitespaces(str[pos])))
			return (0);
		pos++;
	}
	return (1);
}

int	is_map_valid(t_map *map)
{
	int	i;

	i = 0;
	if (map->map_lin == 0)
	{
		map->empty_map = 1;
		return (0);
	}
	while (i < map->map_lin)
	{
		if (!(map_conditions(map, i)))
			return (0);
		if (map->no_empty_line == 0 && !check_whitespace(map->game_map, i))
			return (0);
		map->no_empty_line = 0;
		i++;
	}
	map->no_empty_line = 1;
	if (map->count_player != 1)
		return (0);
	return (1);
}
