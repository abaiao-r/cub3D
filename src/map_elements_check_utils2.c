/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check_utils2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:58:58 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 20:50:23 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_rgb_values(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		write(2, "Error\nRGB values must be between 0 and 255\n", 43);
		return (0);
	}
	return (1);
}

int	check_rgb_is_digit(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (ft_isspace(rgb[i][j]) == 0)
			{
				if (ft_isdigit(rgb[i][j]) == 0)
				{
					write(2, "Error\nRGB values must be numbers\n", 34);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rgb_count_words(char **rgb)
{
	int	i;
	int	count_words;

	i = 0;
	while (rgb[i])
	{
		count_words = ft_count_words(rgb[i]);
		if (count_words > 1)
		{
			write(2, "Error\nRGB values invalid\n", 26);
			return (0);
		}
		i++;
	}
	if (i != 3)
	{
		write(2, "Error\nRGB values invalid\n", 26);
		return (0);
	}
	return (1);
}

int	check_path_count_words(char *path)
{
	int	count_words;

	count_words = ft_count_words(path);
	if (count_words > 1)
	{
		write(2, "Error\nInvalid texture path. Too many arguments\n", 48);
		return (0);
	}
	return (1);
}

int	check_path_extension(char *path)
{
	int		i;
	char	*temp;

	i = 0;
	while (path[i] != '\0' && ft_isspace(path[i]) == 0)
		i++;
	temp = ft_strndup(path, i);
	i = 0;
	while (temp[i] != '\0')
	{
		if (ft_strncmp(temp, "./", 2) != 0 || ft_strncmp(temp + ft_strlen(temp)
				- 4, ".xpm", 4) != 0)
		{
			write(2, "Error\nInvalid texture path on scene description file.\n",
				55);
			free(temp);
			return (0);
		}
		i++;
	}
	free(temp);
	return (1);
}
