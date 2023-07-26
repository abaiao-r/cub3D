/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:50:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/26 15:14:40 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(t_cub *cub, double y, double x)
{
	if (cub->map->game_map[(int)floor(y)][(int)floor(x)] != '1')
		return (1);
	return (0);
}

int move_up(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c + ray->dir_x * SPEED;
	tmp_l = map->player_l + ray->dir_y * SPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->pos_y + ray->dir_y * SPEED)][(int)ray->pos_x] != '1')
		ray->pos_y += ray->dir_y * SPEED;
	if(map->game_map[(int)ray->pos_y][(int)(ray->pos_x + ray->dir_x * SPEED)] != '1')
		ray->pos_x += ray->dir_x * SPEED;
	map->player_c = map->player_c + ray->dir_x * SPEED;
	map->player_l = map->player_l + ray->dir_y * SPEED;
	return (1);
}

int move_down(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c - ray->dir_x * SPEED;
	tmp_l = map->player_l - ray->dir_y * SPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->pos_y + ray->dir_y * SPEED)][(int)ray->pos_x] != '1')
		ray->pos_y -= ray->dir_y * SPEED;
	if(map->game_map[(int)ray->pos_y][(int)(ray->pos_x + ray->dir_x * SPEED)] != '1')
		ray->pos_x -= ray->dir_x * SPEED;
	map->player_c = map->player_c - ray->dir_x * SPEED;
	map->player_l = map->player_l - ray->dir_y * SPEED;
	return (1);
}

int move_right(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c + ray->plane_x * SPEED;
	tmp_l = map->player_l + ray->plane_y * SPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->pos_y + ray->plane_y * SPEED)][(int)ray->pos_x] != '1')
		ray->pos_y += ray->plane_y * SPEED;
	if(map->game_map[(int)ray->pos_y][(int)(ray->pos_x + ray->plane_x * SPEED)] != '1')
		ray->pos_x += ray->plane_x * SPEED;
	map->player_c = map->player_c + ray->plane_x * SPEED;
	map->player_l = map->player_l + ray->plane_y * SPEED;
	return (1);
}

int move_left(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c - ray->plane_x * SPEED;
	tmp_l = map->player_l - ray->plane_y * SPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->pos_y + ray->plane_y * SPEED)][(int)ray->pos_x] != '1')
		ray->pos_y -= ray->plane_y * SPEED;
	if(map->game_map[(int)ray->pos_y][(int)(ray->pos_x + ray->plane_x * SPEED)] != '1')
		ray->pos_x -= ray->plane_x * SPEED;
	map->player_c = map->player_c - ray->plane_x * SPEED;
	map->player_l = map->player_l - ray->plane_y * SPEED;
	return (1);
}

int rotate(t_raycast *ray, int s)
{
	double tmp_dir_x;
	double tmp_plane_x;

	tmp_dir_x = ray->dir_x;
	tmp_plane_x = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(s*SPEED) - ray->dir_y * sin(s*SPEED);
	ray->dir_y = tmp_dir_x * sin(s*SPEED) + ray->dir_y * cos(s*SPEED);
	ray->plane_x = ray->plane_x * cos(s*SPEED) - ray->plane_y * sin(s*SPEED);
	ray->plane_y = tmp_plane_x * sin(s*SPEED) + ray->plane_y * cos(s*SPEED);
	return (1);
}

int key_release(int key, t_cub *cub)
{
	if (key == XK_Escape)
		close_win(cub);
	if (key == XK_w)
		cub->key_state.w = 0;
	if (key == XK_s)
		cub->key_state.s = 0;
	if (key == XK_a)
		cub->key_state.a = 0;
	if (key == XK_d)
		cub->key_state.d = 0;
	if (key == XK_Left)
		cub->key_state.left_arrow = 0;
	if (key == XK_Right)
		cub->key_state.right_arrow = 0;
	raycast(cub);
	return (0);
}





int key_press(int key, t_cub *cub)
{
	if (key == XK_Escape)
    	close_win(cub);
    if (key == XK_w)
		cub->key_state.w = 1;
	if (key == XK_s)
		cub->key_state.s = 1;
	if (key == XK_a)
		cub->key_state.a = 1;
	if (key == XK_d)
		cub->key_state.d = 1;
	if (key == XK_Left)
		cub->key_state.left_arrow = 1;
	if (key == XK_Right)
		cub->key_state.right_arrow = 1;
	raycast(cub);
	return (0);
}
