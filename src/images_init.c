/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/27 13:24:20 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_img	*blank_image(t_cub *cub, t_img *img)
{
	img->img_ptr = mlx_new_image(cub->mlx_ptr, WINDOW_W, WINDOW_H);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
	img->img_w = PX;
	return (img);
}

/*Open images of the different textures*/
static void	copy_pixel_data(t_img *img)
{
	int	*addr;
	int	*text_int_px;
	int	x;
	int	y;

	addr = img->addr;
	text_int_px = ft_calloc(1, sizeof(int) * PX * PX);
	y = 0;
	while (y < PX)
	{
		x = 0;
		while (x < PX)
		{
			text_int_px[y * PX + x] = addr[y * PX + x];
			x++;
		}
		y++;
	}
	img->text_int_px = text_int_px;
	img->img_w = PX;
}

static t_img	*open_xpm_image(t_cub *cub, t_img *img, char *xpm_path, char *dir)
{
	int	x;
	int	y;

	x = PX;
	y = PX;
	img = ft_calloc(1, sizeof(t_img));
	img->dir = ft_strdup(dir);
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr, xpm_path, &x, &y);
	if (!img->img_ptr)
	{
		printf("Error\nInvalid texture path: %s\n", xpm_path);
		printf("texture path might be empty or invalid\n");
		exit(1);
	}
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
	copy_pixel_data(img);
	mlx_destroy_image(cub->mlx_ptr, img->img_ptr);
	return (img);
}

int	**create_int_px(void)
{
	int	i;
	int	**int_px;

	i = 0;
	int_px = ft_calloc(WINDOW_H + 1, sizeof(int *));
	while (i < WINDOW_H)
	{
		int_px[i] = ft_calloc(WINDOW_W + 1, sizeof(int));
		i++;
	}
	return (int_px);
}

void	images_init(t_cub *cub)
{
	cub->int_px = create_int_px();
	cub->img = (t_img **)ft_calloc(5, sizeof(t_img *));
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
	cub->img[4] = ft_calloc(1, sizeof(t_img));
	blank_image(cub, cub->img[4]);
}
