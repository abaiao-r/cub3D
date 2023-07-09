/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:29 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/09 21:13:48 by andrefranci      ###   ########.fr       */
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

typedef struct s_elements_data
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor_colour_r;
	int		floor_colour_g;
	int		floor_colour_b;
	int		ceiling_colour_r;
	int		ceiling_colour_g;
	int		ceiling_colour_b;
}			t_elements_data;

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*win_ptr;
	//t_images	*img_ptr;
	int		n_moves;
	t_map	*map;

}			t_cub;

typedef struct s_elements_var
{
    char *elements[6];
	int		num_elements;
	int		count_elements;
	char	*element;
	char	*temp;
	int		element_len;
}			t_elements_var;

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