/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:50:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/19 21:13:10 by pedperei         ###   ########.fr       */
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

int move_up(t_cub *cub, t_raycast *ray, t_map *map)
{
	(void)cub;
	if(map->game_map[(int)(ray->posX + ray->dirX * MOVESPEED)][(int)ray->posY] == '0')
		ray->posX += ray->dirX * MOVESPEED;
	if(map->game_map[(int)ray->posY][(int)(ray->posX + ray->dirX * MOVESPEED)] == '0')
		ray->posX += ray->dirX * MOVESPEED;
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
		move_up(cub, cub->raycast, cub->map);
	/* if (key == XK_a)
		move_left();
	if (key == XK_s)
		move_down();
	if (key == XK_d)
		move_right(); */
	return (0);
}