/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:50:24 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/27 14:31:33 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* key_release: This function is called when a key is released.
** It checks which key was released and sets the
** corresponding key state to 0.
** It also calls the raycast function.*/
int	key_release(int key, t_cub *cub)
{
	if (key == XK_Escape)
		close_win(cub);
	if (key == XK_w)
		cub->key_state.w = 0;
	if (key == XK_s)
		cub->key_state.s = 0;
	if (key == XK_a)
		cub->key_state.a = 0;
	if (key == XK_d)
		cub->key_state.d = 0;
	if (key == XK_Left)
		cub->key_state.left_arrow = 0;
	if (key == XK_Right)
		cub->key_state.right_arrow = 0;
	raycast(cub);
	return (0);
}

/* key_press: This function is called when a key is pressed.
** It checks which key was pressed and sets the
** corresponding key state to 1.
** It also calls the raycast function.*/
int	key_press(int key, t_cub *cub)
{
	if (key == XK_Escape)
		close_win(cub);
	if (key == XK_w)
		cub->key_state.w = 1;
	if (key == XK_s)
		cub->key_state.s = 1;
	if (key == XK_a)
		cub->key_state.a = 1;
	if (key == XK_d)
		cub->key_state.d = 1;
	if (key == XK_Left)
		cub->key_state.left_arrow = 1;
	if (key == XK_Right)
		cub->key_state.right_arrow = 1;
	raycast(cub);
	return (0);
}
