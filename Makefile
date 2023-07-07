# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedperei <pedperei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 16:03:25 by pedperei          #+#    #+#              #
#    Updated: 2023/07/07 17:09:41 by pedperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings	
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread

# Directories
SRCDIR = ./src
OBJDIR = ./objs

# Source Files

SRCS = 	$(SRCDIR)/map.c \

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT_DIR = libft/
LIBFT_INCLUDE = libft

# Targets
NAME = cub3d

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
			$(CC) $(OBJS) $(CFLAGS) libft/libft.a -o  $(NAME) 

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@ 

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean bonus re run