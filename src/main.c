/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:05:10 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/12 18:06:34 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_mlx_lib(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		return (free_mlx(cub));
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, 1280, 720, "cub3D");
	if (!cub->win_ptr)
		return (free_mlx(cub));
/* 	if (!load_textures(cub))
		return (free_mlx(cub)); */
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
	printf("\n"); // test
	init_mlx_lib(cub);
}
