/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/12 22:33:26 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*Open images of the different textures*/
t_img	*open_xpm_image(t_cub *cub, t_img *img, char *xpm_path)
{
	int			x;
	int			y;

	x = PX;
	y = PX;
	img = ft_calloc(1, sizeof(t_img));
	img->img_ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
			xpm_path, &x, &y);
    img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len, &img->endian);
	return (img);
}

void init_textures(t_cub *cub, t_img **img)
{
	int i = 0;
	while (i < PX)
	{
		int j = 0;
		while (j < PX)
		{
			mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, img[0] ,j * PX,i * PX);
			j++;
		}
		i++;
	}
}

void init_images(t_cub *cub)
{
	cub->img = (t_img **)ft_calloc(5, sizeof(t_img *));
	if (!cub->img)
		return ;
	cub->img[0] = open_xpm_image(cub, cub->img[0], cub->map->elements_data->no_texture);
	cub->img[1] = open_xpm_image(cub, cub->img[1], cub->map->elements_data->so_texture);
	cub->img[2] = open_xpm_image(cub, cub->img[2], cub->map->elements_data->ea_texture);
	cub->img[3] = open_xpm_image(cub, cub->img[3], cub->map->elements_data->we_texture);
	init_textures(cub, cub->img);
}

