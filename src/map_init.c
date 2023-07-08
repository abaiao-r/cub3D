/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:30:51 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/08 12:20:44 by abaiao-r         ###   ########.fr       */
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

int	ft_strlen_mod(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	count_cols(char *map)
{
	int		fd;
	char	*str;
	int		len;

	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	len = 0;
	while (str != NULL)
	{
		if (ft_strlen_mod(str) > len)
			len = ft_strlen_mod(str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (len);
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
	map->col = count_cols(str_map[1]);
	//if (!is_rectangule(map))
	//	return (free_t_map(map, 'r'));
	if (!is_wall(map))
	{
		printf("MAP not OK\n");
		return (NULL);
	}
	else
		printf("MAP OK\n");
	return (map);
}
