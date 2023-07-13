/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/13 20:42:09 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*Open images of the different textures*/
t_img	*open_xpm_image(t_cub *cub, t_img *img, char *xpm_path, char *dir)
{
	int	x;
	int	y;

	x = PX;
	y = PX;
	img = ft_calloc(1, sizeof(t_img));
	img->dir = ft_strdup(dir);
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, xpm_path, &x, &y);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
	return (img);
}

void	init_textures(t_cub *cub, t_img **img)
{
	int	i;
	int	j;

	i = 0;
	while (i < PX)
	{
		j = 0;
		while (j < PX)
		{
			mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, img[0], j * PX,
				i * PX);
			j++;
		}
		i++;
	}
}

t_img	*blank_image(t_cub *cub, t_img *img)
{
	img->img_ptr = mlx_new_image(cub->mlx_ptr, WINDOW_W, WINDOW_H);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
	return (img);
}
void	set_image_pixel(t_img *image, int x, int y, int color)
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
unsigned int	rgb_to_hex(t_elements_data *d, char c)
{
	unsigned int r_hex = 0;
	unsigned int g_hex = 0;
	unsigned int b_hex = 0;

	if (c == 'C')
	{
		r_hex = (unsigned int)d->ceiling_colour_r / 16 * 16 + (unsigned int)d->ceiling_colour_r % 16;
		g_hex = (unsigned int)d->ceiling_colour_g / 16 * 16 + (unsigned int)d->ceiling_colour_g % 16;
		b_hex = (unsigned int)d->ceiling_colour_b / 16 * 16 + (unsigned int)d->ceiling_colour_b % 16;
	}
	if (c == 'F')
	{
		r_hex = (unsigned int)d->floor_colour_r / 16 * 16 + (unsigned int)d->ceiling_colour_r % 16;
		g_hex = (unsigned int)d->floor_colour_g / 16 * 16 + (unsigned int)d->ceiling_colour_g % 16;
		b_hex = (unsigned int)d->floor_colour_b / 16 * 16 + (unsigned int)d->ceiling_colour_b % 16;
	}
	return (r_hex * 65536 + g_hex * 256 + b_hex);
}

void draw_floor_ceiling(t_cub *cub)
{
	int	i;
	int	j;
	t_img *img;

	i = 0;
	img = ft_calloc(1, sizeof(t_img));
	img = blank_image(cub, img);
	while (i < WINDOW_H)
	{
		j = 0;
		while (j < WINDOW_W)
		{
			if (i < WINDOW_H/2)
				set_image_pixel(img, j, i, rgb_to_hex(cub->map->elements_data, 'C'));
			else if (i < WINDOW_H - 1)
				set_image_pixel(img, j, i, rgb_to_hex(cub->map->elements_data, 'F'));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, img->img_ptr, 0, 0);
}

void	init_images(t_cub *cub)
{
	cub->img = (t_img **)ft_calloc(4, sizeof(t_img *));
	if (!cub->img)
		return ;
	cub->img[0] = open_xpm_image(cub, cub->img[0],
			cub->map->elements_data->no_texture, "NO");
	cub->img[1] = open_xpm_image(cub, cub->img[1],
			cub->map->elements_data->so_texture, "SO");
	cub->img[2] = open_xpm_image(cub, cub->img[2],
			cub->map->elements_data->ea_texture, "EA");
	cub->img[3] = open_xpm_image(cub, cub->img[3],
			cub->map->elements_data->we_texture, "WE");
}