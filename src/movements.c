/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:11:38 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/26 16:41:55 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* move_up: This function is called when the W key is pressed.
** It checks if the player can move forward (is_wall) and if so,
** it updates the player's position by adding the direction vector
** to the player's position and the camera plane vector to the player's
** camera plane.*/
int	move_up(t_cub *cub, t_raycast *ray, t_map *map)
{
	double	tmp_c;
	double	tmp_l;

	(void)cub;
	tmp_c = map->player_c + ray->dir_x * SPEED;
	tmp_l = map->player_l + ray->dir_y * SPEED;
	if (!is_wall(cub, tmp_l, tmp_c))
		return (0);
	if (map->game_map[(int)(ray->pos_y + ray->dir_y
			* SPEED)][(int)ray->pos_x] != '1')
		ray->pos_y += ray->dir_y * SPEED;
	if (map->game_map[(int)ray->pos_y][(int)(ray->pos_x + ray->dir_x
		* SPEED)] != '1')
		ray->pos_x += ray->dir_x * SPEED;
	map->player_c = map->player_c + ray->dir_x * SPEED;
	map->player_l = map->player_l + ray->dir_y * SPEED;
	return (1);
}

/*  move_down: This function is called when the S key is pressed.
** It checks if the player can move backward (is_wall) and if so,
** it updates the player's position by subtracting the direction vector
** to the player's position and the camera plane vector to the player's
** camera plane.*/
int	move_down(t_cub *cub, t_raycast *ray, t_map *map)
{
	double	tmp_c;
	double	tmp_l;

	(void)cub;
	tmp_c = map->player_c - ray->dir_x * SPEED;
	tmp_l = map->player_l - ray->dir_y * SPEED;
	if (!is_wall(cub, tmp_l, tmp_c))
		return (0);
	if (map->game_map[(int)(ray->pos_y + ray->dir_y
			* SPEED)][(int)ray->pos_x] != '1')
		ray->pos_y -= ray->dir_y * SPEED;
	if (map->game_map[(int)ray->pos_y][(int)(ray->pos_x + ray->dir_x
		* SPEED)] != '1')
		ray->pos_x -= ray->dir_x * SPEED;
	map->player_c = map->player_c - ray->dir_x * SPEED;
	map->player_l = map->player_l - ray->dir_y * SPEED;
	return (1);
}

/* move_right: This function is called when the D key is pressed.
** It checks if the player can move right (is_wall) and if so,
** it updates the player's position by adding the camera plane vector
** to the player's position and subtracting the direction vector to the player's
** camera plane.*/
int	move_right(t_cub *cub, t_raycast *ray, t_map *map)
{
	double	tmp_c;
	double	tmp_l;

	(void)cub;
	tmp_c = map->player_c + ray->plane_x * SPEED;
	tmp_l = map->player_l + ray->plane_y * SPEED;
	if (!is_wall(cub, tmp_l, tmp_c))
		return (0);
	if (map->game_map[(int)(ray->pos_y + ray->plane_y
			* SPEED)][(int)ray->pos_x] != '1')
		ray->pos_y += ray->plane_y * SPEED;
	if (map->game_map[(int)ray->pos_y][(int)(ray->pos_x + ray->plane_x
		* SPEED)] != '1')
		ray->pos_x += ray->plane_x * SPEED;
	map->player_c = map->player_c + ray->plane_x * SPEED;
	map->player_l = map->player_l + ray->plane_y * SPEED;
	return (1);
}

/*  move_left: This function is called when the A key is pressed.
** It checks if the player can move left (is_wall) and if so,
** it updates the player's position by subtracting the camera plane vector
** to the player's position and adding the direction vector to the player's
** camera plane.*/
int	move_left(t_cub *cub, t_raycast *ray, t_map *map)
{
	double	tmp_c;
	double	tmp_l;

	(void)cub;
	tmp_c = map->player_c - ray->plane_x * SPEED;
	tmp_l = map->player_l - ray->plane_y * SPEED;
	if (!is_wall(cub, tmp_l, tmp_c))
		return (0);
	if (map->game_map[(int)(ray->pos_y + ray->plane_y
			* SPEED)][(int)ray->pos_x] != '1')
		ray->pos_y -= ray->plane_y * SPEED;
	if (map->game_map[(int)ray->pos_y][(int)(ray->pos_x + ray->plane_x
		* SPEED)] != '1')
		ray->pos_x -= ray->plane_x * SPEED;
	map->player_c = map->player_c - ray->plane_x * SPEED;
	map->player_l = map->player_l - ray->plane_y * SPEED;
	return (1);
}

/* rotate: This function is called when the left or right arrow key is pressed.
** It updates the player's direction and camera plane vectors by rotating them
** around the player's position.
** The rotation is done by multiplying the direction and camera plane vectors
** by a rotation matrix.*/
int	rotate(t_raycast *ray, int s)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = ray->dir_x;
	tmp_plane_x = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(s * SPEED) - ray->dir_y * sin(s * SPEED);
	ray->dir_y = tmp_dir_x * sin(s * SPEED) + ray->dir_y * cos(s * SPEED);
	ray->plane_x = ray->plane_x * cos(s * SPEED) - ray->plane_y * \
			sin(s * SPEED);
	ray->plane_y = tmp_plane_x * sin(s * SPEED) + ray->plane_y * cos(s * SPEED);
	return (1);
}
