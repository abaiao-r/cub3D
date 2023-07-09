/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:29 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/09 01:37:30 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../.minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	int		lin;
	int		map_lin;
	int		map_col;
	int		check_wall;
	int		check_chars;
	int		check_elem;
	int		count_player;
	int		no_empty_line;
	int		empty_map;
	int		player_l;
	int		player_c;
	int		elements_end;
	char	**desc_file;
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

typedef struct s_check_elements
{
	char	*element;
	int		element_len;
	int		count_elements;
	int		num_elements;
	int		i;
	int		j;
}			t_check_elements;

/* check_args.c */
int			check_args(int argc, char **argv);

/* map_check.c */
int			check_chars(t_map *map);
int			is_player_empty(char c);
void		is_surrounded(t_map *map, int pos_l, int pos_c);
int			is_map_valid(t_map *map);

/* map_init.c */
int			count_lines(char *map);
int			ft_strlen_mod(const char *str);
int			count_cols(char *map);
char		**read_map(char **str_map, int lines, int start_map);
t_map		*init_map(char **str_map);

/* map_elements_check.c */
int			check_elements(t_map *map);
int			check_extra_args(t_map *map);

#endif