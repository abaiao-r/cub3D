/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 18:32:18 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	is_valid_identifier(char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0 || ft_strncmp(str, "SO", 2) == 0)
		return (1);
	if (ft_strncmp(str, "WE", 2) == 0 || ft_strncmp(str, "EA", 2) == 0)
		return (1);
	if (ft_strncmp(str, "F", 1) == 0 || ft_strncmp(str, "C", 1) == 0)
		return (1);
	if (ft_is_input_only_whitespaces(str) == 1)
		return (1);
	return (0);
}

int	check_extra_args(t_map *map)
{
	int		i;
	char	*temp;

	i = 0;
	while (i < map->elements_end + 1)
	{
		temp = map->desc_file[i];
		ft_skip_whitespace(&temp);
		if (!is_valid_identifier(temp))
		{
			map->check_elem = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

static int check_rgb_values(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		write(2, "Error\nRGB values must be between 0 and 255\n", 43);
		return (0);
	}
	return (1);
}

static int check_rgb_is_digit(char **rgb)
{
	int i;
	int j;

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

static int check_rgb_count_words(char **rgb)
{
	int i;
	int count_words;

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
	return (1);
}

static int check_path_extension(char *path)
{
	int i;
	char *temp;

	i = 0;
	while (path[i] != '\0' && ft_isspace(path[i]) == 0)
		i++;
	temp = ft_strndup(path, i);
	printf("temp:%s\n", temp); // test debug
	i = 0;
	while (temp[i] != '\0')
	{
		if (ft_strncmp(temp, "./", 2) != 0 || ft_strncmp(temp
				+ ft_strlen(temp) - 4, ".xpm", 4) != 0)
		{
			write(2, "Error\nInvalid texture path on scene description file.\n", 55);
			free(temp);
			return (0);
		}
		i++;
	}
	free(temp);
	return (1);
}


static int check_path_count_words(char *path)
{
	int count_words;
	count_words = ft_count_words(path);
	if(count_words > 1)
	{
		write(2, "Error\nInvalid texture path. Too many arguments\n", 48);
		return (0);
	}
	return (1);
}

static char *def_path(char *temp, t_elements_var *elements_var)
{
	int i;
	char *path;

	i = elements_var->element_len;
	while (temp[i] != '\0' && ft_isspace(temp[i]))
		i++;
	printf("elements_var->temp:%s\n", &elements_var->temp[i]); // test debug
	if (ft_strncmp(&elements_var->temp[i], "./", 2) == 0)
	{
		if(check_path_count_words(&elements_var->temp[i]) != 1)
			return (0);
		path = ft_strndup(&elements_var->temp[i], ft_strlen_word(&elements_var->temp[i]));
		printf("entrei\n"); // test debug
	}
	else
		path  = ft_strdup(&elements_var->temp[i]);
	return (path);
}


static int check_textures_path(t_map *map, t_elements_var *elements_var, t_elements_data *elements_data)
{
	char	*path;
	int fd;
	/* int k; */
	char **rgb;

	path = def_path(elements_var->temp, elements_var);
	if (path == NULL)
		return (0);
	/* ft_search_and_replace(elements_var->temp, '\n', '\0');
	k = elements_var->element_len;
	while (elements_var->temp[k] != '\0' && ft_isspace(elements_var->temp[k]))
		k++;
	printf("elements_var->temp:%s\n", &elements_var->temp[k]); // test debug
	if (ft_strncmp(&elements_var->temp[k], "./", 2) == 0)
	{
		if(check_path_count_words(&elements_var->temp[k]) != 1)
			return (0);
		path = ft_strndup(&elements_var->temp[k], ft_strlen_word(&elements_var->temp[k]));
		printf("entrei\n"); // test debug
	}
	else
		path  = ft_strdup(&elements_var->temp[k]); */
	if (ft_strncmp(elements_var->element, "NO", 2) == 0)
	{
		if (check_path_extension(path) == 0)
		{
			free(path);
			return (0);
		}
		elements_data->no_texture = path;
	}
	else if(ft_strncmp(elements_var->element, "SO", 2) == 0)
	{
		if (check_path_extension(path) == 0)
		{
			free(path);
			return (0);
		}
		elements_data->so_texture = path;
	}
	else if (ft_strncmp(elements_var->element, "WE", 2) == 0)
	{
		if (check_path_extension(path) == 0)
		{
			free(path);
			return (0);
		}
		elements_data->we_texture = path;
	}
	else if (ft_strncmp(elements_var->element, "EA", 2) == 0)
	{
		if (check_path_extension(path) == 0)
		{
			free(path);
			return (0);
		}
		elements_data->ea_texture = path;
	}
	else if (ft_strncmp(elements_var->element, "F", 1) == 0)
	{
		rgb = ft_split(path, ',');
		check_rgb_count_words(rgb);
		check_rgb_is_digit(rgb);
		elements_data->floor_colour_r = ft_atoi(rgb[0]);
		elements_data->floor_colour_g = ft_atoi(rgb[1]);
		elements_data->floor_colour_b = ft_atoi(rgb[2]);
		if (check_rgb_values(elements_data->floor_colour_r, elements_data->floor_colour_g, elements_data->floor_colour_b) == 0)
		{
			ft_free_array2d(rgb);
			free(path);
			return (0);
		}
		ft_free_array2d(rgb);
		return (1);
	}
	else if (ft_strncmp(elements_var->element, "C", 1) == 0)
	{
		rgb = ft_split(path, ',');
		check_rgb_count_words(rgb);
		check_rgb_is_digit(rgb);
		elements_data->ceiling_colour_r = ft_atoi(rgb[0]);
		elements_data->ceiling_colour_g = ft_atoi(rgb[1]);
		elements_data->ceiling_colour_b = ft_atoi(rgb[2]);
		if (check_rgb_values(elements_data->ceiling_colour_r, elements_data->ceiling_colour_g, elements_data->ceiling_colour_b) == 0)
		{
			free(path);
			ft_free_array2d(rgb);
			return (0);
		}
		ft_free_array2d(rgb);
		return (1);
	}
	printf("path:%s\n", path); // test debug
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("fd: %d\n", fd); // test debug
		write(2, "Error\nInvalid texture path\n", 27);
		map->check_elem = 1;
		close(fd);
		free(path);
		return (0);
	}
	close(fd);
	free(path);
	write(1, "Texture path is valid\n", 22); // test debug
	return (1);
}


static int	process_element(t_map *map, t_elements_var *elements_var, t_elements_data *elements_data)
{
	elements_var->element = elements_var->elements[elements_var->i];
	elements_var->element_len = ft_strlen(elements_var->element);
	while (elements_var->j < map->lin)
	{
		elements_var->temp = map->desc_file[elements_var->j];
		ft_skip_whitespace(&elements_var->temp);
		if (ft_strncmp(elements_var->temp, elements_var->element,
				elements_var->element_len) == 0
			&& ft_isspace(elements_var->temp[elements_var->element_len]))
		{
			elements_var->count_elements++;
			if (check_textures_path(map, elements_var, elements_data) == 0)
				return (0);
			if (elements_var->count_elements == elements_var->num_elements)
				map->elements_end = elements_var->j;
		}
		elements_var->j++;
	}
	return (1);
}

static void	init_elements_var(t_elements_var *elements_var)
{
	elements_var->elements[0] = "NO";
	elements_var->elements[1] = "SO";
	elements_var->elements[2] = "WE";
	elements_var->elements[3] = "EA";
	elements_var->elements[4] = "F";
	elements_var->elements[5] = "C";
	elements_var->num_elements = sizeof(elements_var->elements)
		/ sizeof(elements_var->elements[0]);
	elements_var->count_elements = 0;
	elements_var->i = 0;
	elements_var->j = 0;
}

int	check_elements(t_map *map)
{
	t_elements_var	*elements_var;
	t_elements_data	*elements_data;

	elements_data = ft_calloc(1, sizeof(t_elements_data));
	elements_var = ft_calloc(1, sizeof(t_elements_var));
	init_elements_var(elements_var);
	while (elements_var->i < elements_var->num_elements)
	{
		elements_var->j = 0;
		process_element(map, elements_var, elements_data);
		elements_var->i++;
	}
	if (elements_var->count_elements != elements_var->num_elements)
	{
		printf("elements_var->count_elements:%d\n", elements_var->count_elements); // test debug
		printf("elements_var->num_elements:%d\n", elements_var->num_elements); // test debug
		map->check_elem = 1;
		free (elements_var);
		return (0);
	}
	printf(" Elements OK\n"); //debug message
	free (elements_var);
	return (1);
}

