/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:30:51 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/07 17:14:28 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*conta linhas existentes no mapa passado no ficheiro .ber
nºlinhas = nº de strings que irão ser alocadas + 1 (NULL terminator)*/
int	count_lines(char *map)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}

/*Aloca memória para gravar o mapa como array de strings (char **)
utiliza-se a funcao get_next_line para ir lendo as linhas 
passadas no ficheiro com a estrutura do mapa (.ber)*/
char	**read_map(char *str_map)
{
	int		fd;
	int		i;
	int		lines;
	char	**map;

	lines = count_lines(str_map);
	if (!lines)
		return (0);
	map = (char **)ft_calloc(lines, sizeof(char *));
	if (!map)
		return (0);
	fd = open(str_map, O_RDONLY);
	if (fd < 0 || fd > 4096)
		return (0);
	i = -1;
	while (++i < lines)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

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
			if (i == 0 || i == (map->lin - 1))
			{
				if (map->game_map[i][j] != '1')
					return (0);
			}
			if (j == 0 || j == (map->col - 1))
			{
				if (map->game_map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	map->check_wall = 1;
	return (1);
}

t_map	*init_map(char **str_map)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	map->game_map = read_map(str_map[1]);
	if (!map->game_map)
		return (NULL);
	map->lin = count_lines(str_map[1]);
	//if (!is_rectangule(map))
	//	return (free_t_map(map, 'r'));
	if (!is_wall(map))
		return (NULL);
	return (map);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	(void)argc;
	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (!cub)
		return (0);
	cub->map = init_map(argv);
	if (!cub->map)
	{
		free(cub);
		return (0);
	}
    int i = 0;
    while (cub->map->game_map[i])
    {
        printf("%s", cub->map->game_map[i]);
        i++;
    }
    
}