/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:50:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/20 18:49:55 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* int key_release(int key, t_cub *cub)
{
    if (key == XK_Escape)
        close_win(cub);
    if (key == XK_w && cub->player->move_y == 1)
		cub->player->move_y = 0;
	if (key == XK_s && cub->player->move_y == -1)
		cub->player->move_y = 0;
	if (key == XK_a && cub->player->move_x == -1)
		cub->player->move_x += 1;
	if (key == XK_d && cub->player->move_x == 1)
		cub->player->move_x -= 1;
	if (key == XK_Left && cub->player->rotate <= 1)
		cub->player->rotate = 0;
	if (key == XK_Right && cub->player->rotate >= -1)
		cub->player->rotate = 0;
	return (0);
} */
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

	tmp_c = map->player_c + ray->dirX * MOVESPEED;
	tmp_l = map->player_l + ray->dirY * MOVESPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->posX + ray->dirX * MOVESPEED)][(int)ray->posY] != '1')
		ray->posX += ray->dirX * MOVESPEED;
	if(map->game_map[(int)ray->posX][(int)(ray->posY + ray->dirY * MOVESPEED)] != '1')
		ray->posY += ray->dirY * MOVESPEED;
	map->player_c = map->player_c + ray->dirX * MOVESPEED;
	map->player_l = map->player_l + ray->dirY * MOVESPEED;
	return (1);
}

int move_down(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c - ray->dirX * MOVESPEED;
	tmp_l = map->player_l - ray->dirY * MOVESPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->posX + ray->dirX * MOVESPEED)][(int)ray->posY] != '1')
		ray->posX -= ray->dirX * MOVESPEED;
	if(map->game_map[(int)ray->posX][(int)(ray->posY + ray->dirY * MOVESPEED)] != '1')
		ray->posY -= ray->dirY * MOVESPEED;
	map->player_c = map->player_c - ray->dirX * MOVESPEED;
	map->player_l = map->player_l - ray->dirY * MOVESPEED;
	return (1);
}

int move_right(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c + ray->planeX * MOVESPEED;
	tmp_l = map->player_l + ray->planeY * MOVESPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->posX + ray->planeX * MOVESPEED)][(int)ray->posY] != '1')
		ray->posX += ray->planeX * MOVESPEED;
	if(map->game_map[(int)ray->posX][(int)(ray->posY + ray->planeY * MOVESPEED)] != '1')
		ray->posY += ray->planeY * MOVESPEED;
	map->player_c = map->player_c + ray->planeX * MOVESPEED;
	map->player_l = map->player_l + ray->planeY * MOVESPEED;
	return (1);
}

int move_left(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	double tmp_c;
	double tmp_l;

	tmp_c = map->player_c - ray->planeX * MOVESPEED;
	tmp_l = map->player_l - ray->planeY * MOVESPEED;
	if (!is_wall(cub, tmp_l,tmp_c))
		return (0);
	if(map->game_map[(int)(ray->posX + ray->planeX * MOVESPEED)][(int)ray->posY] != '1')
		ray->posX -= ray->planeX * MOVESPEED;
	if(map->game_map[(int)ray->posX][(int)(ray->posY + ray->planeY * MOVESPEED)] != '1')
		ray->posY -= ray->planeY * MOVESPEED;
	map->player_c = map->player_c - ray->planeX * MOVESPEED;
	map->player_l = map->player_l - ray->planeY * MOVESPEED;
	return (1);
}


int key_press(int key, t_cub *cub)
{
	if (key == XK_Escape)
    	close_win(cub);
   /*  if (key == XK_Left)
		cub->player->rotate -= 1;
	if (key == XK_Right)
		cub->player->rotate += 1; */
	if (key == XK_w)
	{
		move_up(cub, cub->raycast, cub->map);
		raycast(cub);
	}
	if (key == XK_s)
	{
		move_down(cub, cub->raycast, cub->map);
		raycast(cub);
	}
	if (key == XK_a)
	{
		move_left(cub, cub->raycast, cub->map);
		raycast(cub);
	}
	if (key == XK_d)
	{
		move_right(cub, cub->raycast, cub->map);
		raycast(cub);
	}
	return (0);
}