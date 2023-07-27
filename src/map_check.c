/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:12:12 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/27 16:50:30 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* check_chars: This function checks if the characters in the map are valid.
** It checks if the characters are N, E, S, W, 0 or 1 while it iterates
** through the map.
** If the characters are N, E, S, W, 0 or 1, it returns 1.
** If the characters are not valid, it returns 0.
*/
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

/* check_whitespaces: This function checks if the map has only whitespaces.
** It checks if the map has only whitespaces while it iterates through the map.
** If the map has only whitespaces, it returns 1.
** If the map has not only whitespaces, it returns 0.
*/
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

/* is map valid: This function checks if the map is valid.
** It checks if the map is valid while it iterates through the map.
** If the map is valid, it returns 1.
** If the map is not valid, it returns 0.
*/
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
