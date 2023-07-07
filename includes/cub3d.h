/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:29 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/07 20:19:33 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_map
{
	int			col;
	int			lin;
	int			check_wall;
	int			check_rectangule;
	int			check_chars;
	int			count_player;
	int			count_exit;
	int			count_collect;
	int			check_path_exit;
	int			check_path_collect;
	int			player_l;
	int			player_c;
	char		**game_map;
	char		**save_path;

}				t_map;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	//t_images	*img_ptr;
	int			n_moves;
	t_map		*map;

}				t_cub;


#endif