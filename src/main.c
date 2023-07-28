/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:05:10 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/28 18:39:52 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* print_controls: prints the controls.
 */
static void	print_controls(void)
{
	printf("\n");
	printf("\033[1;36m");
	printf("                 ■■      ■■■■  ■■■■■■■  \n");
	printf("                /■■     ■/// ■/■■////■■ \n");
	printf("  ■■■■■  ■■   ■■/■■    /    /■/■■    /■■\n");
	printf(" ■■///■■/■■  /■■/■■■■■■   ■■■ /■■    /■■\n");
	printf("/■■  // /■■  /■■/■■///■■ /// ■/■■    /■■\n");
	printf("/■■   ■■/■■  /■■/■■  /■■■   /■/■■    ■■ \n");
	printf("//■■■■■ //■■■■■■/■■■■■■/ ■■■■ /■■■■■■■  \n");
	printf(" /////   ////// /////   ////  ///////   \n");
	printf("\033[0m");
	printf("\n");
	printf("\033[1;95m");
	printf("\tW\033[0m: move forward\t");
	printf("\033[1;95m\tS\033[0m: move backward\n");
	printf("\033[1;95m\tA\033[0m: strafe left\t");
	printf("\033[1;95m\tD\033[0m: strafe right\n");
	printf("\033[1;95m\t<\033[0m: rotate left\t");
	printf("\033[1;95m\t>\033[0m: rotate right\n");
	printf("\033[1;95m\tESC\033[0m: exit\n");
	printf("\n");
}

/* init_mlx_lib: initializes the mlx library.
 * It initializes the mlx_ptr and the win_ptr.
 * It then initializes the images.
 * It then initializes the raycast structure.
 * It then sets the camera direction.
 * It then calls the raycast function.
 * It then sets the hooks.
 * @param cub: cub structure.
 * @return: 0 if the mlx library is not initialized, 1 if it is.
 */
int	init_mlx_lib(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		return (close_win_2(cub));
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WINDOW_W, WINDOW_H, "cub3D");
	if (!cub->win_ptr)
		return (close_win_2(cub));
	images_init(cub);
	cub->raycast = ft_calloc(1, sizeof(t_raycast));
	if (!cub->raycast)
		return (close_win(cub));
	set_camera_direction(cub->map, cub->raycast);
	raycast(cub);
	mlx_hook(cub->win_ptr, 17, 1L << 0, close_win, cub);
	mlx_hook(cub->win_ptr, KeyPress, KeyPressMask, key_press, cub);
	mlx_hook(cub->win_ptr, KeyRelease, KeyReleaseMask, key_release, cub);
	mlx_loop_hook(cub->mlx_ptr, raycast, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}

/*  main: main function.
 *  It checks if the arguments are correct.
 *  If the arguments are correct, it initializes the cub structure.
 *  If the cub structure is not initialized, it returns 0.
 *  It then initializes the map.
 *  If the map is not initialized, it returns 0.
 *  It then prints the controls.
 *  It then initializes the mlx library.
 */
int	main(int argc, char **argv)
{
	t_cub	*cub;

	(void)argc;
	if (!check_args(argc, argv))
		return (1);
	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (!cub)
		return (0);
	cub->map = init_map(argv);
	if (!cub->map)
		return (free(cub), 0);
	print_controls();
	init_mlx_lib(cub);
}
