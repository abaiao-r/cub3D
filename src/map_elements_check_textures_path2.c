/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check_textures_path2.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:04:45 by andrefranci       #+#    #+#             */
/*   Updated: 2023/07/11 15:27:14 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  file_exists: checks if the file exists.
 *  It opens the file and if it does not exist, it returns 0.
 *  @param path: path of the texture.
 *  @param map: map structure.
 *  @return: 1 if the file exists, 0 if not.
 */
int	file_exists(char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nTexture file does not exist\n", 35);
		map->check_elem = 1;
		close(fd);
		free(path);
		return (0);
	}
	close(fd);
	free(path);
	return (1);
}
