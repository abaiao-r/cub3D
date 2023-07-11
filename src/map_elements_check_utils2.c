/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check_utils2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:58:58 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/11 11:43:23 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_rgb_values(t_elements_data *elements_data)
{
	if (elements_data->floor_colour_r < 0 || elements_data->floor_colour_r > 255
		|| elements_data->floor_colour_g < 0
		|| elements_data->floor_colour_g > 255
		|| elements_data->floor_colour_b < 0
		|| elements_data->floor_colour_b > 255
		|| elements_data->ceiling_colour_r < 0
		|| elements_data->ceiling_colour_r > 255
		|| elements_data->ceiling_colour_g < 0
		|| elements_data->ceiling_colour_g > 255
		|| elements_data->ceiling_colour_b < 0
		|| elements_data->ceiling_colour_b > 255)
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
					ft_free_array2d(rgb);
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
			ft_free_array2d(rgb);
			return (0);
		}
		i++;
	}
	if (i != 3)
	{
		write(2, "Error\nRGB values invalid\n", 26);
		ft_free_array2d(rgb);
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
