/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_extra_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:17:12 by andrefranci       #+#    #+#             */
/*   Updated: 2023/07/11 15:33:17 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  is_valid_identifier: checks if the element is a valid identifier.
 *  @param str: element.
 *  @return: 1 if the element is a valid identifier, 0 if not.
 */
static int	is_valid_identifier(char *str)
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

/*  check_extra_args: checks if there are extra arguments by checking
 *  if the elements of the map are valid identifiers.
 *  If there are not, it returns 0.
 *  @param map: map structure.
 *  @return: 1 if there are no extra arguments, 0 if not.
 */
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
