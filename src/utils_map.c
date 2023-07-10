/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:55:40 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/10 18:55:55 by pedperei         ###   ########.fr       */
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
