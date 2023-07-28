/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/28 17:35:25 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* blank_image: creates a blank image
** This function initializes a blank image with the
** specified width and height (WINDOW_W and WINDOW_H).
** It creates an image using the provided dimensions and
** sets up the necessary properties for further manipulation
** and rendering. */
static t_img	*blank_image(t_cub *cub, t_img *img)
{
	img->img_ptr = mlx_new_image(cub->mlx_ptr, WINDOW_W, WINDOW_H);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
	img->img_w = PX;
	return (img);
}

/* copy_pixel_data: copies pixel data
** This function copies the pixel data from the
** provided image to the text_int_px array.
** It does this by iterating through the image's
** pixel data and copying it to the text_int_px array.
** This is done to avoid having to load the image
** every time we need to render it. */
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

/* open_xpm_image: opens an xpm image
** This function opens an xpm image and copies
** the pixel data to the text_int_px array.
** It does this by calling the mlx_xpm_file_to_image
** function and passing the provided xpm_path.
** It then copies the pixel data to the text_int_px
** array by calling the copy_pixel_data function.
** It then destroys the image using mlx_destroy_image
** to avoid memory leaks. */
static t_img	*open_xpm_image(t_cub *cub, t_img *img, char *xpm_path,
		char *dir)
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
		write (2, "Error\nInvalid texture path: texture path \
might be empty or invalid\n", 68);
		free(img->dir);
		free(img);
		close_win(cub);
		exit(1);
	}
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
	copy_pixel_data(img);
	mlx_destroy_image(cub->mlx_ptr, img->img_ptr);
	return (img);
}

/* create_int_px: creates an int pixel
** This function creates an int pixel by allocating
** memory for the int_px array and then allocating
** memory for each row of the int_px array.
** It is used to store color values for each pixel
** of the image. */
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

/*  images_init: initializes the images
**  This function initializes the images by calling
**  the create_int_px function to create the int_px array.
**  It then allocates memory for the img array and
**  initializes the images by calling the open_xpm_image
**  function for each image. */
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
