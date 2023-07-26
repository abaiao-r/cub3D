/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:14:35 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/26 18:23:39 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  is_wall: This function checks if the player is facing a wall.
**  It returns 1 if the player is facing a wall and 0 if not.
**  It checks if the player is facing a wall by checking the
**  game_map array in the position where the player is facing.
**  If the position is a '1', it means that the player is facing a wall.
**  If the position is a '0', it means that the player is not facing a wall.
*/
int	is_wall(t_cub *cub, double y, double x)
{
	if (cub->map->game_map[(int)floor(y)][(int)floor(x)] != '1')
		return (1);
	return (0);
}
