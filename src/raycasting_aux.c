/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:10:27 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/27 14:02:47 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->line_len / 4) + x;
	image->addr[pixel] = color;
}

/* rgb_to_hex: converts rgb values to hex
 * first, we convert the rgb values to hex values
 * then, we multiply the red value by 65536 (256 * 256)
 * then, we multiply the green value by 256
 * then, we add the red, green, and blue values together
 * then, we return the hex value
 * note: we use unsigned int to avoid overflow
 */


static unsigned int	rgb_to_hex(t_elements_data *d, char c)
{
	if (c == 'C')
		return (d->ceiling_colour_r * 65536 + d->ceiling_colour_g * 256 + d->ceiling_colour_b);
	if (c == 'F')
		return (d->floor_colour_r * 65536 + d->floor_colour_g * 256 + d->floor_colour_b);
	return (0);
}

void	draw_floor_ceiling(t_cub *cub)
{
	int		i;
	int		j;
	t_img	*img;

	i = 0;
	img = cub->img[4];
	while (i < WINDOW_H)
	{
		j = 0;
		while (j < WINDOW_W)
		{
			if (cub->int_px[i][j] > 0)
				set_image_pixel(img, j, i, cub->int_px[i][j]);
			else if (i < WINDOW_H / 2)
				set_image_pixel(img, j, i, rgb_to_hex(cub->map->elements_data,
						'C'));
			else if (i < WINDOW_H - 1)
				set_image_pixel(img, j, i, rgb_to_hex(cub->map->elements_data,
						'F'));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, img->img_ptr, 0, 0);
}
