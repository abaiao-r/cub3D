/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:05:10 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 19:07:04 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	{
		free(cub);
		return (0);
	}
	i = 0;
	while (i < cub->map->map_lin)
	{
		printf("%s", cub->map->game_map[i]);
		i++;
	}
	printf("\n");
}
