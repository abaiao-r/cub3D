/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:53:25 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/29 18:16:03 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  apply_texture_to_column: This function applies the texture to the column
**  of the wall by calculating the img_x_pos and img_y_pos.
**  It also calculates the img_step and img_pos.
**  It also checks if the texture pixel is greater than 0, because if it is
**  less than 0, it means that the pixel is transparent.
*/
void	apply_texture_to_column(t_cub *cub, t_img *img, t_raycast *ray, int x)
{
	int	y;

	img->img_x_pos = (int)(ray->wall_hit_x * img->img_w);
	if ((ray->side_hit == 0 && ray->ray_dir_x < 0) || (ray->side_hit == 1
			&& ray->ray_dir_y > 0))
		img->img_x_pos = img->img_w - img->img_x_pos - 1;
	img->img_step = (double)img->img_w / ray->line_height;
	img->img_pos = (ray->draw_start - WINDOW_H / 2 + ray->line_height / 2)
		* img->img_step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		img->img_y_pos = (int)img->img_pos & (img->img_w - 1);
		img->img_pos += img->img_step;
		if (img->text_int_px[img->img_w * img->img_y_pos + img->img_x_pos] > 0)
			cub->int_px[y][x] = img->text_int_px[img->img_w * img->img_y_pos
				+ img->img_x_pos];
		y++;
	}
}

/*  search_texture: This function searches for the texture in the img array
**  based on the dir.
**  If the dir is "SO", it means that the texture to be applied is the
**  South texture.
**  If the dir is "NO", it means that the texture to be applied is the
**  North texture.
**  If the dir is "EA", it means that the texture to be applied is the
**  East texture.
**  If the dir is "WE", it means that the texture to be applied is the
**  West texture.
*/
t_img	*search_texture(t_img **images, char *dir)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(dir, images[i]->dir) == 0)
			return (images[i]);
		i++;
	}
	return (NULL);
}

/*  select_texture: This function selects the texture to be applied to the
**  wall based on the ray->side_hit and ray->dir_x and ray->dir_y.
**  If the ray->side_hit is 1 and ray->dir_y is greater than 0, it means that
**  the ray hit a wall looking down, so the texture to be applied is the
**  South texture.
**  If the ray->side_hit is 1 and ray->dir_y is less or equal to 0, it means that
**  the ray hit a wall looking up, so the texture to be applied is the
**  North texture.
**  If the ray->side_hit is 0 and ray->dir_x is greater or equal to 0, it means
**  that the ray hit a wall looking to the right, so the texture to be applied
**  is the East texture.
**  If the ray->side_hit is 0 and ray->dir_x is less than 0, it means that
**  the ray hit a wall looking to the left, so the texture to be applied
**  is the West texture.
*/
t_img	*select_texture(t_cub *cub, t_raycast *ray)
{
	if (ray->side_hit == 1 && ray->ray_dir_y > 0)
		return (search_texture(cub->img, "SO"));
	if (ray->side_hit == 1 && ray->ray_dir_y <= 0)
		return (search_texture(cub->img, "NO"));
	if (ray->side_hit == 0 && ray->ray_dir_x >= 0)
		return (search_texture(cub->img, "EA"));
	if (ray->side_hit == 0 && ray->ray_dir_x < 0)
		return (search_texture(cub->img, "WE"));
	return (NULL);
}

/*  prep_draw_line: This function prepares the variables to draw the line.
**  It calculates the line height, the draw start and draw end.
**  It also calculates the wall_hit_x, which is the exact value where the wall
**  was hit(could be the y coordinate if the side_hit == 1) but it is always used
**  to calculate the x coordinate of the texture.
*/
void	prep_draw_line(t_raycast *ray)
{
	ray->line_height = (int)(1.5 * WINDOW_H / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WINDOW_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_H / 2;
	if (ray->draw_end >= WINDOW_H)
		ray->draw_end = WINDOW_H - 1;
	if (ray->side_hit == 0)
		ray->wall_hit_x = ray->pos_y + ray->wall_dist * ray->ray_dir_y;
	else
		ray->wall_hit_x = ray->pos_x + ray->wall_dist * ray->ray_dir_x;
	ray->wall_hit_x -= floor((ray->wall_hit_x));
}
