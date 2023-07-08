/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:29 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/08 13:54:55 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../.minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_map
{
	int		col;
	int		lin;
	int		check_wall;
	int		check_rectangule;
	int		check_chars;
	int		count_player;
	int		count_exit;
	int		count_collect;
	int		check_path_exit;
	int		check_path_collect;
	int		player_l;
	int		player_c;
	char	**game_map;
	char	**save_path;

}			t_map;

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*win_ptr;
	//t_images	*img_ptr;
	int		n_moves;
	t_map	*map;

}			t_cub;

/* map_init.c */
int			count_lines(char *map);
int			ft_strlen_mod(const char *str);
int			count_cols(char *map);
char		**read_map(char *str_map);
t_map		*init_map(char **str_map);

/* map_check.c */
int			check_chars(t_map *map);
int			is_player_empty(char c);
int			is_surrounded(t_map *map, int pos_l, int pos_c);
int			is_wall(t_map *map);

#endif