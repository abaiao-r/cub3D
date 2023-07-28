/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/28 18:49:20 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* close_win: This function closes the window.
** It frees the memory allocated for the map.
** It then frees the memory allocated for the images by iterating through the
** images array.
** It then clears the window and destroys the image and the window.
** It then frees the memory allocated for the int_px array.
*/
int	close_win(t_cub *cub)
{
	int	i;

	map_free(cub->map);
	i = 0;
	while (i < 4)
	{
		free(cub->img[i]->dir);
		free(cub->img[i]->text_int_px);
		free(cub->img[i]);
		i++;
	}
	mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->img[i]->img_ptr);
	free(cub->img[i]);
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
	ft_free_int_array(cub->int_px);
	free(cub->img);
	free(cub->raycast);
	free(cub);
	exit(0);
	return (1);
}

/* close_win_2: This function closes the window.
** It frees the memory allocated for the map.
** It then frees the memory allocated for the mlx_ptr and the win_ptr.
*/
int	close_win_2(t_cub *cub)
{
	map_free(cub->map);
	if (!cub->mlx_ptr)
	{
		free(cub);
		write(2, "Error\nmlx_ptr failure\n", 22);
		return (1);
	}
	if (cub->mlx_ptr && !cub->win_ptr)
	{
		mlx_destroy_display(cub->mlx_ptr);
		free(cub->mlx_ptr);
		free(cub);
		write(2, "Error\nmlx_win failure\n", 22);
		return (1);
	}
	exit(0);
	return (1);
}

/*  ft_free_int_array: This function frees the memory allocated for the int_px
** array.
*/
void	ft_free_int_array(int **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
