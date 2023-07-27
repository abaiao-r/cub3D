/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:42:40 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/27 14:31:29 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  set_camera_direction_ns: set the camera direction based
** on the map->direction
** if the direction is S, the camera will be looking down
** if the direction is N, the camera will be looking up
*/
static void	set_camera_direction_ns(t_map *map, t_raycast *ray)
{
	if (map->direction == 'S')
	{
		ray->dir_x = 0;
		ray->dir_y = 1;
		ray->plane_x = -0.66;
		ray->plane_y = 0;
	}
	else if (map->direction == 'N')
	{
		ray->dir_x = 0;
		ray->dir_y = -1;
		ray->plane_x = 0.66;
		ray->plane_y = 0;
	}
}

/* set_camera_direction_ew: set the camera direction based on the map->direction
** if the direction is E, the camera will be looking to the right
** because the camera plane is perpendicular to the camera direction
** if the direction is W, the camera will be looking to the left
*/
static void	set_camera_direction_ew(t_map *map, t_raycast *ray)
{
	if (map->direction == 'E')
	{
		ray->dir_x = 1;
		ray->dir_y = 0;
		ray->plane_x = 0;
		ray->plane_y = 0.66;
	}
	else if (map->direction == 'W')
	{
		ray->dir_x = -1;
		ray->dir_y = 0;
		ray->plane_x = 0;
		ray->plane_y = -0.66;
	}
}

/* set_camera_direction: set the camera direction based on the map->direction
** it is called only once, when the mlx_loop_hook is called for the first time
*/
void	set_camera_direction(t_map *map, t_raycast *ray)
{
	if (map->direction == 'S' || map->direction == 'N')
		set_camera_direction_ns(map, ray);
	else if (map->direction == 'E' || map->direction == 'W')
		set_camera_direction_ew(map, ray);
}

/* raycast: main function for raycasting
** it is called every time the mlx_loop_hook is called
** it is responsible for moving the player and drawing the image
** it returns 0 if everything went well
*/
int	raycast(t_cub *cub)
{
	if (cub->key_state.w)
		move_up(cub, cub->raycast, cub->map);
	if (cub->key_state.s)
		move_down(cub, cub->raycast, cub->map);
	if (cub->key_state.a)
		move_left(cub, cub->raycast, cub->map);
	if (cub->key_state.d)
		move_right(cub, cub->raycast, cub->map);
	if (cub->key_state.left_arrow)
		rotate(cub->raycast, -1);
	if (cub->key_state.right_arrow)
		rotate(cub->raycast, 1);
	init_raycast_vars(cub, cub->map, cub->raycast);
	draw_floor_ceiling(cub);
	return (0);
}
