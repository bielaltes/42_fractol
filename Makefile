# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:47:17 by baltes-g          #+#    #+#              #
#    Updated: 2023/03/06 17:15:22 by baltes-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=fractol
CFLAGS=-Wall -Wextra -Werror -g
LIB_DIR=INC/libft/
MLX_DIR=INC/minilibx_opengl
MLX=libmlx.a
MLX_FLAGS=-LINC/minilibx_opengl -lmlx -framework OpenGL -framework AppKit
INC_MLX=mlx.h
LIB=libft.a
LIB_INC=libft.h

SRC =	SRC/MAIN/fractol.c
		
BNS_DIR = BNS/
BNS_NAME = checker

OBJ=$(SRC:.c=.o)

OBJ_BNS=$(SRC_BNS:.c=.o)

all:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) $(NAME)

%.o: %.c $(INC) 
	@echo "Compilant $@"
	@$(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_DIR)$(LIB) $(OBJ) 
	@echo "Enllaçant $@"
	@$(CC) $(CFLAGS) $(LIB_DIR)$(LIB) $(OBJ) $(MLX_FLAGS) $< -o $(NAME)

bonus:
	@$(MAKE) -C $(BNS_DIR)
	@cp $(BNS_DIR)$(BNS_NAME) .

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re bonus