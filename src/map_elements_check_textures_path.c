/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check_textures_path.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:51:36 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/12 17:57:40 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  init_rgb_values: initializes the rgb values.
 *  @param elements_data: elements_data structure.
 *  @param rgb: rgb values.
 *  @param c: character.
 * @return: 1 if the rgb values are correct, 0 if not.
 */
static void	init_rgb_values(t_elements_data *elements_data, char **rgb, char c)
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

/*  parse_rgb_values: parses the rgb values.
 *  Split the path of the texture by the comma and stores it in rgb.
 *  If the number of words is not 3, it returns 0.
 *  Then it checks if the rgb values are digits.
 *  If they are not, it returns 0 and frees the allocated memory.
 *  Then it stores the rgb values in the elements_data structure.
 *  If the rgb values are not between 0 and 255, it returns 0.
 *  If the rgb values are correct, it frees the allocated memory.
 *  @param path: path of the texture.
 *  @param map: map structure.
 *  @param elements_data: elements_data structure.
 *  @param c: character.
 *  @return: 1 if the rgb values are correct, 0 if not.
 */
static int	parse_rgb_values(char *path, t_map *map,
		t_elements_data *elements_data, char c)
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

/*  verify_path: verifies if the path of the texture is correct.
 *  It checks if the path has the correct extension.
 *  If it does not, it returns 0 and frees the allocated memory.
 *  Then it checks if the element is NO, SO, WE or EA.
 *  If it is, it checks if the path of the texture is already defined.
 *  If the path of the texture is not already defined, it copies the path 
 *  to store in the map structure.
 *  @param path: path of the texture.
 *  @param elements_var: elements_var structure.
 *  @param elements_data: elements_data structure.
 *  @return: 1 if the path of the texture is correct, 0 if not.
 */
static int	verify_path(char *path, t_elements_var *elements_var,
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
			&& elements_data->no_texture == NULL)
			elements_data->no_texture = ft_strdup(path);
		else if (ft_strncmp(elements_var->element, "SO", 2) == 0
			&& elements_data->so_texture == NULL)
			elements_data->so_texture = ft_strdup(path);
		else if (ft_strncmp(elements_var->element, "WE", 2) == 0
			&& elements_data->we_texture == NULL)
			elements_data->we_texture = ft_strdup(path);
		else if (ft_strncmp(elements_var->element, "EA", 2) == 0
			&& elements_data->ea_texture == NULL)
			elements_data->ea_texture = ft_strdup(path);
	}
	return (1);
}

/*  def_path: defines the path of the texture.
 *  It checks if the path starts with ./.
 *  If it does, it checks if the path has only one word.
 *  If it does, it copies the path.
 *  If it does not, it returns 0.
 *  @param temp: temporary string.
 *  @param elements_var: elements_var structure.
 *  @return: the path of the texture.
 */
static char	*def_path(char *temp, t_elements_var *elements_var)
{
	int		i;
	char	*path;
	char	*temp2;
	size_t	len;

	i = elements_var->element_len;
	while (temp[i] != '\0' && ft_isspace(temp[i]))
		i++;
	if (ft_strncmp(&elements_var->temp[i], "./", 2) == 0)
	{
		if (check_path_count_words(&elements_var->temp[i]) != 1)
			return (0);
		path = ft_strndup(&elements_var->temp[i],
				ft_strlen_word(&elements_var->temp[i]));
		printf("path: %s\n", path);
	}
	else
	{
		temp2 = ft_strchr(&elements_var->temp[i], '\n');
		if (temp2 == NULL)
			return (0);
		len = temp2 - &elements_var->temp[i];
		path = ft_strndup(&elements_var->temp[i], len);
	}
	return (path);
}

/*  check_textures_path: checks if the path of the texture is correct.
 *  def_path: defines the path of the texture.
 *  verify_path: verifies if the path of the texture is correct.
 * parse_rgb_values: parses the rgb values.
 * file_exists: checks if the file exists.
 * @param map: map structure.
 * @param elements_var: elements_var structure.
 * @param elements_data: elements_data structure.
 * @return: 1 if the path of the texture is correct, 0 if not.
 */
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
