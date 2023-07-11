/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:05:10 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/11 23:26:43 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_mlx_lib(t_cub *cub)
{
	int		i;

	i = 0;
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, 1280, 720, "cub3D");
	mlx_loop(cub->mlx_ptr);
	mlx_get_time
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;
	int		i;

	(void)argc;
	if (!check_args(argc, argv))
		return (1);
	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (!cub)
		return (0);
	cub->map = init_map(argv);
	if (!cub->map)
		return(free(cub), 0);
	init_mlx_lib(cub);
	i = 0;
	while (i < cub->map->map_lin)
	{
		printf("%s", cub->map->game_map[i]);
		i++;
	}
	printf("\n");
}
