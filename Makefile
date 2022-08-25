# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 14:55:36 by gjohana           #+#    #+#              #
#    Updated: 2022/08/25 19:03:41 by gjohana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =  src/main.c src/engine.c src/parser.c src/read_map.c src/get_player_info.c src/get_player_info2.c src/utils.c src/calc_utils.c\
		src/key_update_utils.c src/check_map.c src/parser_utils.c src/get_rgb.c src/check_rgb.c

SRCS_B = 
OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a mlx/libmlx.a
#LIB		=	libft/libft.a mlx_linux/libmlx.a

HEADER	=	cub3d.h

CC		=	gcc
#CC		=	clang

FLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g3

RM		= rm -rf

MLX 	= -framework OpenGL -framework AppKit -lmlx -L /Users/annapopova/X11
#MLX		= -lXext -lX11 -lm

.PHONY:		all	clean	fclean	re	bonus	libft

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

all:		$(NAME)


$(NAME):	$(LIB) $(OBJ) $(HEADER)
			$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)

bonus:	
	@make OBJ="$(OBJ_B)" all

$(LIB):
			@$(MAKE) -C libft/
			@$(MAKE) -C mlx/
#			@$(MAKE) -C mlx_linux/

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean
			@$(MAKE) -C mlx/ clean

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)

re:			fclean all