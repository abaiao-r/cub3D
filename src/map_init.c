/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:30:51 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/10 19:06:31 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*Aloca memória para gravar o mapa como array de strings (char **)
utiliza-se a funcao get_next_line para ir lendo as linhas 
passadas no ficheiro com a estrutura do mapa (.ber)*/
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

t_map	*init_map(char **str_map)
{
	t_map	*map;
	int		map_start;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	map->desc_file = read_desc_file(str_map[1]);
	if (!map->desc_file)
		return (NULL);
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
	else
		printf("MAP OK\n");
	return (map);
}
