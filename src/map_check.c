/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:12:12 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/08 13:45:59 by pedperei         ###   ########.fr       */
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

int	is_char_valid(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W' || c == '0' || c == '1')
		return (1);
	if (ft_isspace((int)c))
		return (1);
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
	map->col = ft_strlen_mod(map->game_map[pos_l]);
	if (!(pos_c >= 0 && pos_c < map->col))
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

int	is_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lin)
	{
		j = 0;
		while (map->game_map[i][j] != '\n' && map->game_map[i][j] != '\0')
		{
			if (is_player_empty(map->game_map[i][j]))
				is_surrounded(map, i, j);
			if (!is_char_valid(map->game_map[i][j]))
				map->check_chars = 1;
			if (is_player(map->game_map[i][j]))
				map->count_player++;
			if (map->check_wall == 1 || map->check_chars == 1
				|| map->count_player > 1)
				return (0);
			j++;
		}
		i++;
	}
	map->check_wall = 1;
	return (1);
}
