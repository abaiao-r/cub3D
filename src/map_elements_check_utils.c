/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:51:36 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/11 11:44:07 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_textures_path(t_map *map, t_elements_var *elements_var,
		t_elements_data *elements_data)
{
	char	*path;

	path = def_path(elements_var->temp, elements_var);
	if (path == NULL)
		return (0);
	if (verify_path(path, elements_var, elements_data) == 0)
		return (0);
	if (ft_strncmp(elements_var->element, "F", 1) == 0)
	{
		if (parse_rgb_values(path, map, elements_data, 'F') == 0)
			return (0);
		return (1);
	}
	if (ft_strncmp(elements_var->element, "C", 1) == 0)
	{
		if (parse_rgb_values(path, map, elements_data, 'C') == 0)
			return (0);
		return (1);
	}
	if (file_exists(path, map) == 0)
		return (0);
	return (1);
}

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

int	verify_path(char *path, t_elements_var *elements_var,
		t_elements_data *elements_data)
{
	if (ft_strncmp(elements_var->element, "NO", 2) == 0
		|| ft_strncmp(elements_var->element, "SO", 2) == 0
		|| ft_strncmp(elements_var->element, "WE", 2) == 0
		|| ft_strncmp(elements_var->element, "EA", 2) == 0)
	{
		if (check_path_extension(path) == 0)
			return (free(path), 0);
		if (ft_strncmp(elements_var->element, "NO", 2) == 0
			&& elements_data->no_texture != NULL)
			elements_data->no_texture = ft_strdup(path);
		else if (ft_strncmp(elements_var->element, "SO", 2) == 0
			&& elements_data->so_texture != NULL)
			elements_data->so_texture = ft_strdup(path);
		else if (ft_strncmp(elements_var->element, "WE", 2) == 0
			&& elements_data->we_texture != NULL)
			elements_data->we_texture = ft_strdup(path);
		else if (ft_strncmp(elements_var->element, "EA", 2) == 0
			&& elements_data->ea_texture != NULL)
			elements_data->ea_texture = ft_strdup(path);
	}
	return (1);
}

char	*def_path(char *temp, t_elements_var *elements_var)
{
	int		i;
	char	*path;

	i = elements_var->element_len;
	while (temp[i] != '\0' && ft_isspace(temp[i]))
		i++;
	if (ft_strncmp(&elements_var->temp[i], "./", 2) == 0)
	{
		if (check_path_count_words(&elements_var->temp[i]) != 1)
			return (0);
		path = ft_strndup(&elements_var->temp[i],
				ft_strlen_word(&elements_var->temp[i]));
	}
	else
		path = ft_strdup(&elements_var->temp[i]);
	return (path);
}

void	init_rgb_values(t_elements_data *elements_data, char **rgb, char c)
{
	if (c == 'F')
	{
		elements_data->floor_colour_r = ft_atoi(rgb[0]);
		elements_data->floor_colour_g = ft_atoi(rgb[1]);
		elements_data->floor_colour_b = ft_atoi(rgb[2]);
	}
	else if (c == 'C')
	{
		elements_data->ceiling_colour_r = ft_atoi(rgb[0]);
		elements_data->ceiling_colour_g = ft_atoi(rgb[1]);
		elements_data->ceiling_colour_b = ft_atoi(rgb[2]);
	}
}

int	parse_rgb_values(char *path, t_map *map, t_elements_data *elements_data, char c)
{
	char	**rgb;

	rgb = ft_split(path, ',');
	if (rgb == NULL)
	{
		write(2, "Error\nRGB parsing failed!\n", 26);
		map->check_elem = 1;
		return (free(path), 0);
	}
	if (check_rgb_count_words(rgb) == 0 || check_rgb_is_digit(rgb) == 0)
		return (free(path), 0);
	if (c == 'F')
		init_rgb_values(elements_data, rgb, c);
	else if (c == 'C')
		init_rgb_values(elements_data, rgb, c);
	if (check_rgb_values(elements_data) == 0)
	{
		free(path);
		ft_free_array2d(rgb);
		return (0);
	}
	free(path);
	ft_free_array2d(rgb);
	return (1);
}
