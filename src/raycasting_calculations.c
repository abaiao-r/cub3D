/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:48:25 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/28 16:35:53 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  calc_camera_distance: This function calculates the camera distance.
**  It checks if the side is 0.
**  If the side is 0, it means that the ray is facing the left side of the map.
**  If the side is 1, it means that the ray is facing the right side of the map.
*/
static void	calc_camera_distance(t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

/*  perform_dda: This function performs the DDA algorithm.
**  It checks if the ray hit a wall.
**  If the ray hit a wall, it sets the hit variable to 1.
**  If the ray didn't hit a wall, it continues the DDA algorithm.
**  It checks if the side distance x is less than the side distance y.
**  If the side distance x is less than the side distance y, it means that
**  the ray is facing the left side of the map.
**  If the side distance x is greater than the side distance y, it means that
**  the ray is facing the right side of the map.
*/
static void	perform_dda(t_raycast *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->game_map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

/*  calc_step_side_dist: This function calculates the step and the 
**  side distance.
**  It calculates the step and the side distance based on the ray direction.
**  If the ray direction is less than 0, it means that the ray is facing
**  the left side of the map.
**  If the ray direction is greater than 0, it means that the ray is facing
**  the right side of the map.
*/
static void	calc_step_side_dist(t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

/*  init_ray_vars: This function initializes the ray variables.
**  It calculates the camera_x, ray_dir_x, ray_dir_y, delta_dist_x,
**  delta_dist_y, map_x and map_y.
*/
static void	init_ray_vars(t_raycast *ray, int x, t_map *map)
{
	ray->camera_x = 2 * x / (double)WINDOW_W - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->map_x = (int)map->player_c;
	ray->map_y = (int)map->player_l;
}

/*  raycast: This function is responsible for the raycasting.
**  It calculates the ray direction and the delta distance.
**  It also calculates the step and the side distance.
**  It also performs the DDA algorithm.
**  It also calculates the camera distance.
**  It also prepares the draw line.
**  It also applies the texture to the column.
*/
void	init_raycast_vars(t_cub *cub, t_map *map, t_raycast *ray)
{
	int		x;
	t_img	*img;
	int		color;

	(void)cub;
	(void)color;
	x = -1;
	ray->pos_x = map->player_c;
	ray->pos_y = map->player_l;
	ft_free_int_array(cub->int_px);
	cub->int_px = create_int_px();
	while (++x < WINDOW_W)
	{
		init_ray_vars(ray, x, map);
		calc_step_side_dist(ray);
		perform_dda(ray, map);
		calc_camera_distance(ray);
		prep_draw_line(ray);
		img = select_texture(cub, ray);
		apply_texture_to_column(cub, img, ray, x);
	}
}
