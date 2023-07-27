/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:55:40 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/27 16:49:46 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* count_lines: This function counts the number of lines in the map.
** It opens the map.
** It reads the map line by line.
** It counts the number of lines.
** It closes the map.
** It returns the number of lines.
*/
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

/* ft_strlen_mod: This function counts the number of characters in the line.
** It counts the number of characters in the line until it finds a new line.
** It returns the number of characters in the line.
*/
int	ft_strlen_mod(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

/* count_cols: This function counts the number of columns in the map.
** It opens the map.
** It reads the map line by line.
** It counts the number of characters in the line.
** It compares the number of characters in the line with the number of columns.
** It returns the number of columns.
*/
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
