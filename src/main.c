/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:05:10 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/17 21:00:58 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int raycast(t_cub *cub)
{
	init_raycast_vars(cub, cub->map, cub->raycast);
	return 0;
}


int	init_mlx_lib(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		return (free_mlx(cub));
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WINDOW_H, WINDOW_W, "cub3D");
	if (!cub->win_ptr)
		return (free_mlx(cub));
/* 	if (!load_textures(cub))
		return (free_mlx(cub)); */
	init_images(cub);
	raycast(cub);
	draw_floor_ceiling(cub);
	mlx_hook(cub->win_ptr, 17, 1L << 0, close_win, cub);
	//mlx_hook(cub->win_ptr, 2, 1L << 0, key_press, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	int		i; // test

	(void)argc;
	if (!check_args(argc, argv))
		return (1);
	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (!cub)
		return (0);
	cub->map = init_map(argv);

	if (!cub->map)
		return(free(cub), 0);
	i = 0; // test
	while (i < cub->map->map_lin)
	{
		printf("%s", cub->map->game_map[i]);
		i++;
	}
	init_mlx_lib(cub);
}
