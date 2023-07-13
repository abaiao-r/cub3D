/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:42:40 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/13 21:11:00 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	define_direction_camera(t_map *map, t_raycast *ray)
{
	if (map->direction == 'N')
	{
		ray->dirX = 0;
		ray->dirY = 1;
		ray->planeX = -0.66;
		ray->planeY = 0;
	}
	else if (map->direction == 'S')
	{
		ray->dirX = 0;
		ray->dirY = -1;
		ray->planeX = 0.66;
		ray->planeY = 0;
	}
	else if (map->direction == 'E')
	{
		ray->dirX = 1;
		ray->dirY = 0;
		ray->planeX = 0;
		ray->planeY = -0.66;
	}
	else if (map->direction == 'W')
	{
		ray->dirX = -1;
		ray->dirY = 0;
		ray->planeX = 0;
		ray->planeY = 0.66;
	}
}

int	delta_dist(int dir)
{
	if (dir == 0)
		return (1000000);
	else
		return (abs(1 / dir));
}

void	init_ray_vars(t_raycast *ray, int x)
{
	ray->cameraX = 2 * x / WINDOW_W - 1;
	ray->rayDirX = ray->dirX + ray->planeX * ray->cameraX;
	ray->rayDirY = ray->dirY + ray->planeY * ray->cameraX;
	ray->deltaDistX = delta_dist(ray->rayDirX);
	ray->deltaDistY = delta_dist(ray->rayDirY);
	ray->mapX = (int)ray->posX;
	ray->mapY = (int)ray->posY;
}

void	calc_step_side_dist(t_raycast *ray)
{
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
	}
}

void	perform_dda(t_raycast *ray, t_map *map)
{
	while (ray->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		//Check if ray has hit a wall
		if (map->game_map[ray->mapX][ray->mapY] == '1')
			ray->hit = 1;
	}
}

void	calc_camera_distance(t_raycast *ray)
{
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
	else
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
}

void	prep_draw_line(t_raycast *ray)
{
	//Calculate height of line to draw on screen
	ray->lineHeight = (int)(WINDOW_H / ray->perpWallDist);
	//calculate lowest and highest pixel to fill in current stripe
	ray->drawStart = -ray->lineHeight / 2 + WINDOW_H / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + WINDOW_H / 2;
	if (ray->drawEnd >= WINDOW_H)
		ray->drawEnd = WINDOW_H - 1;
	if (ray->side == 0)
		ray->wallX = ray->posY + ray->perpWallDist * ray->rayDirY;
	else
		ray->wallX = ray->posX + ray->perpWallDist * ray->rayDirX;
	ray->wallX -= floor((ray->wallX));
}

t_img   *search_texture(t_img **images, char *dir)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if(ft_strcmp(dir, images[i]->dir) == 0)
            return (images[i]);
        i++;
    }
    return (NULL);
}


t_img   *select_texture(t_cub *cub, t_raycast *ray)
{
    if (ray->side == 1 && ray->dirY > 0)
        return(search_texture(cub->img, "SO"));
    if (ray->side == 1 && ray->dirY <= 0)
        return(search_texture(cub->img, "NO"));
    if (ray->side == 0 && ray->dirX > 0)
        return(search_texture(cub->img, "EA"));
    if (ray->side == 0 && ray->dirX <= 0)
        return(search_texture(cub->img, "WE"));
    return (NULL);
}

void	init_raycast_vars(t_cub *cub, t_map *map, t_raycast *ray)
{
	int	x;
    t_img   *img;

	(void)cub;
	x = -1;
	ray = ft_calloc(1, sizeof(t_raycast));
	ray->posX = map->player_l;
	ray->posY = map->player_c;
	define_direction_camera(map, ray);
	while (++x < map->map_lin)
	{
		init_ray_vars(ray, x);
		calc_step_side_dist(ray);
		perform_dda(ray, map);
		calc_camera_distance(ray);
		prep_draw_line(ray);
        img = select_texture(cub, ray);
        img->imgXpos = (int)(ray->wallX * img->imgW);
        if ((ray->side == 0 && ray->rayDirX > 0) || (ray->side == 1 && ray->rayDirY < 0))
            img->imgXpos = img->imgW - img->imgXpos - 1;
	}
}
