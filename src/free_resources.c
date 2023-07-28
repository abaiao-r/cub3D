/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/28 17:38:53 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	close_win_aux(t_cub *cub, int i)
{
	free(cub->img[i]->dir);
	free(cub->img[i]->text_int_px);
	free(cub->img[i]);
}

/* still a draft */
int	close_win(t_cub *cub)
{
	int	i;

	map_free(cub->map);
	i = 0;
	while (i < 4)
	{
		if (cub->img[i])
			close_win_aux(cub, i);
		i++;
	}
	mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
	if (cub->img[i])
	{
		mlx_destroy_image(cub->mlx_ptr, cub->img[i]->img_ptr);
		free(cub->img[i]);
	}
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

/* still a draft */
int	free_mlx(t_cub *cub)
{
	if (cub->win_ptr && cub->mlx_ptr)
	{
		mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	}
	free(cub->mlx_ptr);
	free(cub->win_ptr);
	free(cub->map);
	free(cub);
	exit(0);
}
