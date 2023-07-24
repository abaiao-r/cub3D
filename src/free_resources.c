/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:18:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/24 15:26:14 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* still a draft */
int close_win(t_cub *cub)
{
    //free das cenas do map
    map_free(cub->map);
    //todo: free das texturas
    //mlx_destroy_image(cub->mlx_ptr, cub->text->no);

    mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
    mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
    mlx_destroy_display(cub->mlx_ptr);
    // free da struct cub
    free(cub->mlx_ptr);
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
int    free_mlx(t_cub *cub)
{
    //free das cenas do map
    
    if (cub->win_ptr && cub->mlx_ptr)
    {
        mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
        //todo: free das texturas
        //mlx_destroy_image(cub->mlx_ptr, cub->text->no);
        mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
    } 
    // free da struct cub
    free(cub->mlx_ptr);
    free (cub->win_ptr);
    free(cub->map);
    free(cub);
    exit(0);
}
