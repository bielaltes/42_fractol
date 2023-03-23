# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:47:17 by baltes-g          #+#    #+#              #
#    Updated: 2023/03/23 12:39:56 by baltes-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=fractol
CFLAGS=-Wall -Wextra -Werror -O3
LIB_DIR=INC/libft/
MLX_DIR=INC/minilibx_opengl
MLX=libmlx.a
MLX_FLAGS=-LINC/minilibx_opengl -lmlx -framework OpenGL -framework AppKit
INC_MLX=mlx.h
LIB=libft.a
LIB_INC=libft.h

SRC =	SRC/main.c 					\
		SRC/SETS/sets.c				\
		SRC/SETS/mandelbrot.c		\
		SRC/UTILS/color.c			\
		SRC/UTILS/hooks.c			\
		SRC/UTILS/init.c			\
		SRC/UTILS/parse.c			\
		SRC/UTILS/double_atoi.c		\
		SRC/UTILS/pixel.c			\
		SRC/SETS/julia.c			\
		SRC/SETS/burning.c			
		

OBJ=$(SRC:.c=.o)

OBJ_BNS=$(SRC_BNS:.c=.o)

all:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) $(NAME)

%.o: %.c $(INC) 
	@echo "Compilant $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_DIR)$(LIB) $(OBJ) 
	@echo "Enllaçant $@"
	@$(CC) $(CFLAGS) $(LIB_DIR)$(LIB) $(OBJ) $(MLX_FLAGS) $< -o $(NAME)

bonus:
	@$(MAKE) -C $(BNS_DIR)
	@cp $(BNS_DIR)$(BNS_NAME) .

clean:
	rm -f $(OBJ) $(OBJ_BNS)

clean_all:
	rm -f $(OBJ) $(OBJ_BNS)
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

fclean_all: clean_all
	rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean 

re: fclean all

re_all: fclean_all all

.PHONY: clean clean_all fclean fclean_all all re re_all bonus