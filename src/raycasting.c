/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:42:40 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/26 14:51:20 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_camera_direction(t_map *map, t_raycast *ray)
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
	else if (map->direction == 'E')
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

/* int	delta_dist(int dir)
{
	if (dir == 0)
		return (1000000);
	else
		return (fabs(1 / dir));
} */

void	init_ray_vars(t_raycast *ray, int x, t_map *map)
{
	ray->camera_x = 2 * x / (double)WINDOW_W - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->delta_dist_x = fabs(1/ray->ray_dir_x);
	ray->delta_dist_y = fabs(1/ray->ray_dir_y);
	ray->map_x = (int)map->player_c;
	ray->map_y = (int)map->player_l;
}

void	calc_step_side_dist(t_raycast *ray)
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

void	perform_dda(t_raycast *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
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
		/* if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > WINDOW_H - 0.25
			|| ray->map_x > WINDOW_W - 1.25)
			break ; */
		//Check if ray has hit a wall
		if (map->game_map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calc_camera_distance(t_raycast *ray)
{
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void	prep_draw_line(t_raycast *ray)
{
	//Calculate height of line to draw on screen
	ray->line_height = (int)(WINDOW_H / ray->perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	ray->draw_start = -(ray->line_height) / 2 + WINDOW_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_H / 2;
	if (ray->draw_end >= WINDOW_H)
		ray->draw_end = WINDOW_H - 1;
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor((ray->wall_x));
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
    if (ray->side == 1 && ray->dir_y > 0)
        return(search_texture(cub->img, "SO"));
    if (ray->side == 1 && ray->dir_y <= 0)
        return(search_texture(cub->img, "NO"));
    if (ray->side == 0 && ray->dir_x >= 0)
        return(search_texture(cub->img, "EA"));
    if (ray->side == 0 && ray->dir_x < 0)
        return(search_texture(cub->img, "WE"));
    return (NULL);
}

void	init_raycast_vars(t_cub *cub, t_map *map, t_raycast *ray)
{
	int	x;
	int	y;
    t_img   *img;
	int color;
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
        img->img_x_pos = (int)(ray->wall_x * img->img_w);
        if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1 && ray->ray_dir_y > 0))
            img->img_x_pos = img->img_w - img->img_x_pos - 1;
		img->img_step = (double)img->img_w / ray->line_height;
		img->img_pos = (ray->draw_start - WINDOW_H/2 + ray->line_height /2) * img->img_step;
		y = ray->draw_start;
		while (y < ray->draw_end)
		{
			img->img_y_pos = (int)img->img_pos & (img->img_w - 1);
			img->img_pos += img->img_step;
			if (img->text_int_px[img->img_w * img->img_y_pos + img->img_x_pos] > 0)
				cub->int_px[y][x] = img->text_int_px[img->img_w * img->img_y_pos + img->img_x_pos];
			y++;
		}
	}
}
