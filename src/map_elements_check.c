/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/09 22:08:30 by andrefranci      ###   ########.fr       */
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

void ft_search_and_replace(char *str, char find, char replace)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			str[i] = replace;
		i++;
	}
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
	int j;
	int count_words;

	i = 0;
	while (rgb[i])
	{
		count_words = 0;
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (ft_isspace(rgb[i][j]) == 0)
			{
				count_words++;
				if(count_words > 1)
				{
					write(2, "Error\nRGB values invalid\n", 26);
					return (0);
				}
				while (ft_isspace(rgb[i][j]) == 0 && rgb[i][j] != '\0')
					j++;
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

static int check_textures_path(t_map *map, t_elements_var *elements_var)
{
	char	*path;
	int fd;
	int k;
	t_elements_data *elements_data;
	char **rgb;

	elements_data = ft_calloc(1, sizeof(t_elements_data));
	ft_search_and_replace(elements_var->temp, '\n', '\0');
	k = elements_var->element_len;
	while (elements_var->temp[k] != '\0' && ft_isspace(elements_var->temp[k]))
		k++;
	printf("elements_var->temp:%s\n", &elements_var->temp[k]); // test debug
	if (ft_strncmp(&elements_var->temp[k], "./", 2) == 0)
	{
		path = ft_strdup(&elements_var->temp[k]);
		printf("entrei\n"); // test debug
	}
	else
		path  = ft_strdup(&elements_var->temp[k]); 
	if (ft_strncmp(elements_var->element, "NO", 2) == 0)
	{
		elements_data->no_texture = path;
	}
	else if(ft_strncmp(elements_var->element, "SO", 2) == 0)
	{
		elements_data->so_texture = path;
	}
	else if (ft_strncmp(elements_var->element, "WE", 2) == 0)
	{
		elements_data->we_texture = path;
	}
	else if (ft_strncmp(elements_var->element, "EA", 2) == 0)
	{
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
			free(path);
			return (0);
		}
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
			return (0);
		}
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


static int	process_element(t_map *map, t_elements_var *elements_var, int i, int j)
{
	elements_var->element = elements_var->elements[i];
	elements_var->element_len = ft_strlen(elements_var->element);
	while (j < map->lin)
	{
		elements_var->temp = map->desc_file[j];
		ft_skip_whitespace(&elements_var->temp);
		if (ft_strncmp(elements_var->temp, elements_var->element,
				elements_var->element_len) == 0
			&& ft_isspace(elements_var->temp[elements_var->element_len]))
		{
			elements_var->count_elements++;
			if (check_textures_path(map, elements_var) == 0)
			{
				return (0);
			} //here
			if (elements_var->count_elements == elements_var->num_elements)
				map->elements_end = j;
		}
		j++;
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
}

int	check_elements(t_map *map)
{
	t_elements_var	*elements_var;
	int				i;
	int j;

	elements_var = calloc(1, sizeof(t_elements_var));
	init_elements_var(elements_var);
	i = 0;
	while (i < elements_var->num_elements)
	{
		j = 0;
		process_element(map, elements_var, i, j);
		i++;
	}
	if (elements_var->count_elements != elements_var->num_elements)
	{
		map->check_elem = 1;
		return (0);
	}
	printf(" Elements OK\n"); //debug message
	return (1);
}

/* int	check_elements(t_map *map)
{
	char	*elements[6];
	int		i;
	int		j;
	int		num_elements;
	int		count_elements;
	char	*element;
	char	*temp;
	int		element_len;

	elements[0] = "NO";
	elements[1] = "SO";
	elements[2] = "WE";
	elements[3] = "EA";
	elements[4] = "F";
	elements[5] = "C";
	num_elements = sizeof(elements) / sizeof(elements[0]);
	i = 0;
	count_elements = 0;
	while (i < num_elements)
	{
		element = elements[i];
		element_len = ft_strlen(element);
		j = 0;
		while (j < map->lin)
		{
			temp = map->desc_file[j];
			ft_skip_whitespace(&temp);
			if (ft_strncmp(temp, element, element_len) == 0
				&& ft_isspace(temp[element_len]))
			{
				count_elements++;
				if (count_elements == num_elements)
					map->elements_end = j;
			}
			j++;
		}
		i++;
	}
	if (count_elements != num_elements)
	{
		map->check_elem = 1;
		return (0);
	}
	printf("OK\n"); //debug message
	return (1);
} */
