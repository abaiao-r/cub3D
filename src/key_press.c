/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:50:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/24 14:09:26 by abaiao-r         ###   ########.fr       */
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

	tmp_c = map->player_c + ray->dirX * SPEED;
	tmp_l = map->player_l + ray->dirY * SPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->posY + ray->dirY * SPEED)][(int)ray->posX] != '1')
		ray->posY += ray->dirY * SPEED;
	if(map->game_map[(int)ray->posY][(int)(ray->posX + ray->dirX * SPEED)] != '1')
		ray->posX += ray->dirX * SPEED;
	map->player_c = map->player_c + ray->dirX * SPEED;
	map->player_l = map->player_l + ray->dirY * SPEED;
	return (1);
}

int move_down(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c - ray->dirX * SPEED;
	tmp_l = map->player_l - ray->dirY * SPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->posY + ray->dirY * SPEED)][(int)ray->posX] != '1')
		ray->posY -= ray->dirY * SPEED;
	if(map->game_map[(int)ray->posY][(int)(ray->posX + ray->dirX * SPEED)] != '1')
		ray->posX -= ray->dirX * SPEED;
	map->player_c = map->player_c - ray->dirX * SPEED;
	map->player_l = map->player_l - ray->dirY * SPEED;
	return (1);
}

int move_right(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c + ray->planeX * SPEED;
	tmp_l = map->player_l + ray->planeY * SPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->posY + ray->planeY * SPEED)][(int)ray->posX] != '1')
		ray->posY += ray->planeY * SPEED;
	if(map->game_map[(int)ray->posY][(int)(ray->posX + ray->planeX * SPEED)] != '1')
		ray->posX += ray->planeX * SPEED;
	map->player_c = map->player_c + ray->planeX * SPEED;
	map->player_l = map->player_l + ray->planeY * SPEED;
	return (1);
}

int move_left(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c - ray->planeX * SPEED;
	tmp_l = map->player_l - ray->planeY * SPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->posY + ray->planeY * SPEED)][(int)ray->posX] != '1')
		ray->posY -= ray->planeY * SPEED;
	if(map->game_map[(int)ray->posY][(int)(ray->posX + ray->planeX * SPEED)] != '1')
		ray->posX -= ray->planeX * SPEED;
	map->player_c = map->player_c - ray->planeX * SPEED;
	map->player_l = map->player_l - ray->planeY * SPEED;
	return (1);
}

int rotate(t_raycast *ray, int s)
{
	double tmp_dir_x;
	double tmp_plane_x;

	tmp_dir_x = ray->dirX;
	tmp_plane_x = ray->planeX;
	ray->dirX = ray->dirX * cos(s*SPEED) - ray->dirY * sin(s*SPEED);
	ray->dirY = tmp_dir_x * sin(s*SPEED) + ray->dirY * cos(s*SPEED);
	ray->planeX = ray->planeX * cos(s*SPEED) - ray->planeY * sin(s*SPEED);
	ray->planeY = tmp_plane_x * sin(s*SPEED) + ray->planeY * cos(s*SPEED);
	return (1);
}

int key_press(int key, t_cub *cub)
{
	if (key == XK_Escape)
    	close_win(cub);
    if (key == XK_Right)
		rotate(cub->raycast, 1);
	if (key == XK_Left)
		rotate(cub->raycast, -1);
	if (key == XK_w)
		move_up(cub, cub->raycast, cub->map);
	if (key == XK_s)
		move_down(cub, cub->raycast, cub->map);
	if (key == XK_a)
		move_left(cub, cub->raycast, cub->map);
	if (key == XK_d)
		move_right(cub, cub->raycast, cub->map);
	raycast(cub);
	return (0);
}
