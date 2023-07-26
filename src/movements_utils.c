/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:14:35 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/26 16:14:57 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_wall(t_cub *cub, double y, double x)
{
	if (cub->map->game_map[(int)floor(y)][(int)floor(x)] != '1')
		return (1);
	return (0);
}
