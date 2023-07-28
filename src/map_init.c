/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:30:51 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/28 17:36:57 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* read_desc_file: This function reads the description file.
** It counts the number of lines in the description file.
** It allocates memory for the file.
** It opens the description file.
** It reads the description file.
** It closes the description file.
** It returns the file.
*/
char	**read_desc_file(char *desc_file)
{
	int		fd;
	int		i;
	int		lines;
	char	**file;

	lines = count_lines(desc_file);
	if (!lines)
		return (0);
	file = (char **)ft_calloc(lines + 1, sizeof(char *));
	if (!file)
		return (0);
	fd = open(desc_file, O_RDONLY);
	if (fd < 0 || fd > 4096)
		return (0);
	i = -1;
	while (++i < lines)
		file[i] = get_next_line(fd);
	close(fd);
	return (file);
}

/* read_map: This function reads the map.
** It allocates memory for the map.
** It reads the map from position start_map.
** Start_map is the index of the first line of the map.
** Copy the map to the map variable.
** It returns the map.
*/
char	**read_map(char **desc_file, int lines, int start_map)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char **)ft_calloc(lines - start_map + 1, sizeof(char *));
	if (!map)
		return (0);
	while (i < start_map)
		i++;
	j = -1;
	while ((i + ++j) < lines)
		map[j] = ft_strdup(desc_file[i + j]);
	map[j] = NULL;
	return (map);
}

/* copy_map: This function copies the map.
** It allocates memory for the map.
** It copies the map to the map variable.
** It returns the blank map.
*/
char	**copy_map(t_map *map)
{
	char	**blank_map;
	int		i;

	blank_map = (char **)ft_calloc(map->map_lin + 1, sizeof(char *));
	i = 0;
	while (i < map->map_lin)
	{
		blank_map[i] = ft_calloc(ft_strlen(map->game_map[i]) + 1, sizeof(char));
		i++;
	}
	blank_map[i] = NULL;
	return (blank_map);
}

/* index_map_start: This function returns
** the index of the first line of the map.
** It iterates through the description file until it
** finds the first line of the map.
** It returns the index of the first line of the map.
*/
int	index_map_start(t_map *map)
{
	int	i;

	i = map->elements_end + 1;
	while (i < map->lin)
	{
		if (!ft_is_input_only_whitespaces(map->desc_file[i]))
			break ;
		i++;
	}
	return (i);
}

/* init_map: This function initializes the map.
** It allocates memory for the map.
** It reads the description file.
** It counts the number of lines in the description file.
** It checks the elements of the description file.
** It checks the extra arguments of the description file.
** It reads the map.
** It copies the map.
** It checks if the map is valid.
** It returns the map.
*/
t_map	*init_map(char **str_map)
{
	t_map	*map;
	int		map_start;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	map->desc_file = read_desc_file(str_map[1]);
	if (!map->desc_file)
		return (free(map), NULL);
	map->lin = count_lines(str_map[1]);
	if (!check_elements(map))
		return (map_error_msg(map));
	map_start = index_map_start(map);
	if (!check_extra_args(map))
		return (map_error_msg(map));
	map->game_map = read_map(map->desc_file, map->lin, map_start);
	if (!map->game_map)
		return (NULL);
	map->map_lin = map->lin - map_start;
	map->save_path = copy_map(map);
	if (!is_map_valid(map))
		return (map_error_msg(map));
	return (map);
}
