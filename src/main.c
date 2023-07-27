/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:05:10 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/27 12:51:51 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_mlx_lib(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		return (free_mlx(cub));
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WINDOW_W, WINDOW_H, "cub3D");
	if (!cub->win_ptr)
		return (free_mlx(cub));
	images_init(cub);
	cub->raycast = ft_calloc(1, sizeof(t_raycast));
	set_camera_direction(cub->map, cub->raycast);
	raycast(cub);
	int i = 0;
	while (i < cub->map->map_lin)
	{
		printf("%s", cub->map->game_map[i]);
		i++;
	}
	mlx_hook(cub->win_ptr, 17, 1L << 0, close_win, cub);
	mlx_hook(cub->win_ptr, KeyPress, KeyPressMask, key_press, cub);
	mlx_hook(cub->win_ptr, KeyRelease, KeyReleaseMask, key_release, cub);
	mlx_loop_hook(cub->mlx_ptr, raycast, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	int i; // test
	(void)argc;
	if (!check_args(argc, argv))
		return (1);
	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (!cub)
		return (0);
	cub->map = init_map(argv);
	if (!cub->map)
		return (free(cub), 0);
	init_mlx_lib(cub);
	i = 0; // test
	while (i < cub->map->map_lin)
	{
		printf("%s", cub->map->game_map[i]);
		i++;
	}
}
