# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:03:25 by pedperei          #+#    #+#              #
#    Updated: 2023/07/11 15:58:44 by abaiao-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings	
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

# Directories
SRCDIR = ./src
OBJDIR = ./objs

# Source Files

SRCS = 	$(SRCDIR)/main.c \
		$(SRCDIR)/check_args.c \
		$(SRCDIR)/free_map_aux.c \
		$(SRCDIR)/map_check.c \
		$(SRCDIR)/map_check_extra_args.c \
		$(SRCDIR)/map_conditions.c \
		$(SRCDIR)/map_elements_check_textures_path_utils.c \
		$(SRCDIR)/map_elements_check.c \
		$(SRCDIR)/map_elements_check_textures_path.c \
		$(SRCDIR)/map_elements_check_textures_path2.c \
		$(SRCDIR)/map_init.c \
		$(SRCDIR)/utils_map.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT_DIR = libft/
LIBFT_INCLUDE = libft

MLX_LIB_DIR = .minilibx-linux/
MLX_INCLUDE = -I mlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Targets
NAME = cub3D

all: 	$(NAME)

bonus:	all

clean:
		rm -rf $(OBJDIR)
		cd libft && make clean

fclean:	clean
		rm -f $(NAME)
		cd libft && make fclean

run:	all
		./$(NAME)

re:		fclean all

lldb:	all
		lldb $(NAME)

gdb:	all
		gdb $(NAME)

valgrind: 	all
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

$(NAME): 	$(OBJS)
			$(MAKE) -C $(LIBFT_DIR) bonus
			$(MAKE) -C $(MLX_LIB_DIR)
			$(CC) $(OBJS) $(CFLAGS) $(MLX_INCLUDE) libft/libft.a $(MLX_FLAGS) -o  $(NAME) 

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@ 

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean bonus re run
