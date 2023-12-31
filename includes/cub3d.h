/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:24:29 by pedperei          #+#    #+#             */
/*   Updated: 2023/07/29 15:38:16 by pedperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../.minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PX 64
# define WINDOW_H 480
# define WINDOW_W 640
# define SPEED 0.0525

typedef struct s_key_state
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left_arrow;
	int				right_arrow;
}					t_key_state;

typedef struct s_elements_data
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	int				floor_colour_r;
	int				floor_colour_g;
	int				floor_colour_b;
	int				ceiling_colour_r;
	int				ceiling_colour_g;
	int				ceiling_colour_b;
}					t_elements_data;

typedef struct s_map
{
	int				lin;
	int				map_lin;
	int				map_col;
	int				check_wall;
	int				check_chars;
	int				check_elem;
	int				check_extra_args;
	int				count_player;
	int				no_empty_line;
	int				empty_map;
	double			player_l;
	double			player_c;
	char			direction;
	int				elements_end;
	char			**desc_file;
	char			**game_map;
	char			**save_path;
	t_elements_data	*elements_data;

}					t_map;

typedef struct s_img
{
	char			*dir;
	int				img_w;
	int				img_x_pos;
	double			img_step;
	int				img_y_pos;
	double			img_pos;
	void			*img_ptr;
	int				*addr;
	int				*text_int_px;
	int				height;
	int				width;
	int				bpp;
	int				endian;
	int				line_len;
}					t_img;

typedef struct s_raycast
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			cam_plane_x;
	double			cam_plane_y;
	double			cam_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			wall_dist;
	double			wall_hit_x;
	double			step;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				is_hit;
	int				side_hit;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_raycast;

typedef struct s_cub
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**textures;
	int				**int_px;
	t_raycast		*raycast;
	t_img			**img;
	t_map			*map;
	t_key_state		key_state;

}					t_cub;

typedef struct s_elements_var
{
	char			*elements[6];
	int				num_elements;
	int				count_elements;
	char			*element;
	char			*temp;
	int				element_len;
	int				i;
	int				j;
}					t_elements_var;

/* check_args.c */
int					check_args(int argc, char **argv);

/* free_map_aux.c*/
void				free_str_array(char **str_arr);
void				map_free(t_map *map);
t_map				*map_error_msg(t_map *map);

/* free_resources.c */
int					close_win(t_cub *cub);
int					close_win_2(t_cub *cub);

/* key_handler.c */
int					key_release(int key, t_cub *cub);
int					key_press(int key, t_cub *cub);

/*  images_init.c */
void				images_init(t_cub *cub);
int					**create_int_px(void);

/* map_check.c */
int					check_chars(t_map *map);
int					is_player_empty(char c);
void				is_surrounded(t_map *map, int pos_l, int pos_c);
int					is_map_valid(t_map *map);

/* map_check_extra_args */
int					check_extra_args(t_map *map);

/* map_init.c */
int					count_lines(char *map);
int					ft_strlen_mod(const char *str);
int					count_cols(char *map);
char				**read_map(char **str_map, int lines, int start_map);
t_map				*init_map(char **str_map);

/* map_elements_check.c */
int					check_elements(t_map *map);

/* map_check_textures_path_utils.c */
int					check_rgb_values(t_elements_data *elements_data);
int					check_rgb_is_digit(char **rgb);
int					check_rgb_count_words(char **rgb);
int					check_path_extension(char *path);
int					check_path_count_words(char *path);

/* map_elements_check_textures_path.c */
int					check_textures_path(t_map *map,
						t_elements_var *elements_var,
						t_elements_data *elements_data);

/* map_elements_check_textures_path2.c */
int					file_exists(char *path, t_map *map);

/* movements.c */
int					move_up(t_cub *cub, t_raycast *ray, t_map *map);
int					move_down(t_cub *cub, t_raycast *ray, t_map *map);
int					move_left(t_cub *cub, t_raycast *ray, t_map *map);
int					move_right(t_cub *cub, t_raycast *ray, t_map *map);
int					rotate(t_raycast *ray, int s);

/*  movements_utils.c */
int					is_wall(t_cub *cub, double y, double x);

/* raycasting_aux.c */
void				draw_floor_ceiling(t_cub *cub);

/* raycasting.c */
void				set_camera_direction(t_map *map, t_raycast *ray);
int					raycast(t_cub *cub);

/* raycasting_calculations.c */
void				init_raycast_vars(t_cub *cub, t_map *map, t_raycast *ray);

/* raycasting_textures.c */
void				apply_texture_to_column(t_cub *cub, t_img *img,
						t_raycast *ray, int x);
t_img				*search_texture(t_img **images, char *dir);
t_img				*select_texture(t_cub *cub, t_raycast *ray);
void				prep_draw_line(t_raycast *ray);

/*utils_map.c*/
int					count_lines(char *map);
int					ft_strlen_mod(const char *str);
int					count_cols(char *map);

/*map_conditions.c*/
int					map_conditions(t_map *map, int i);

void				draw_floor_ceiling(t_cub *cub);

void				set_camera_direction(t_map *map, t_raycast *ray);
int					raycast(t_cub *cub);
void				ft_free_int_array(int **array);

#endif