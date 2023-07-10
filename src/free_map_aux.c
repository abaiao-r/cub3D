/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:47:13 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/10 23:16:17 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_str_array(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr[i]);
	free(str_arr);
	str_arr = NULL;
}

void	map_free(t_map *map)
{
	free_str_array(map->desc_file);
	free_str_array(map->game_map);
	free_str_array(map->save_path);
	free(map);
}

t_map	*map_error_msg(t_map *map)
{
	if (map->check_elem == 1)
	{
		free_str_array(map->desc_file);
		free(map);
		return (NULL);
	}
	if (map->empty_map == 1)
		write(2, "Error\nEmpty map\n", 16);
	else if (map->check_wall == 1)
		write(2, "Error\nMap not surrounded by walls\n", 34);
	else if (map->check_chars == 1)
		write(2, "Error\nInvalid character in map\n", 32);
	else if (map->count_player != 1)
		write(2, "Error\nInvalid number of players\n", 33);
	else if (map->no_empty_line == 0)
		write(2, "Error\nEmpty line in the map\n", 28);
	map_free(map);
	return (NULL);
}
