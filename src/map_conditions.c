/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:03:17 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/19 19:05:31 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_char_valid(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W' || c == '0' || c == '1')
		return (1);
	if (ft_isspace((int)c))
		return (2);
	return (0);
}

int	is_player_empty(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W' || c == '0')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

void	is_surrounded(t_map *map, int pos_l, int pos_c)
{
	if (!(pos_l >= 0 && pos_l < map->lin))
	{
		map->check_wall = 1;
		return ;
	}
	map->map_col = ft_strlen_mod(map->game_map[pos_l]);
	if (!(pos_c >= 0 && pos_c < map->map_col))
	{
		map->check_wall = 1;
		return ;
	}
	if (map->save_path[pos_l][pos_c] == '1')
		return ;
	if (map->game_map[pos_l][pos_c] == '1')
		return ;
	map->save_path[pos_l][pos_c] = '1';
	is_surrounded(map, pos_l + 1, pos_c);
	is_surrounded(map, pos_l, pos_c + 1);
	is_surrounded(map, pos_l - 1, pos_c);
	is_surrounded(map, pos_l, pos_c - 1);
	return ;
}

int	map_conditions(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->game_map[i][j] != '\n' && map->game_map[i][j] != '\0')
	{
		if (is_player_empty(map->game_map[i][j]))
			is_surrounded(map, i, j);
		if (is_char_valid(map->game_map[i][j]) == 1)
			map->no_empty_line = 1;
		if (!is_char_valid(map->game_map[i][j]))
			map->check_chars = 1;
		if (is_player(map->game_map[i][j]))
		{
			map->count_player++;
			map->player_l = (double)i + 0.5;
			map->player_c = (double)j + 0.5;
			map->direction = map->game_map[i][j];
		}
		if (map->check_wall == 1 || map->check_chars == 1
			|| map->count_player > 1)
			return (0);
		j++;
	}
	return (1);
}
