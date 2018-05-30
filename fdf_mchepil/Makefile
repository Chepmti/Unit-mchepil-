# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchepil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 14:53:15 by mchepil           #+#    #+#              #
#    Updated: 2018/04/18 14:53:18 by mchepil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = 		fdf

gcc = 		gcc
C_FLAGS = 	-Wall -Wextra -Werror -g
FRAM = 		-L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit -g
FRAM = 		-framework OpenGL -framework AppKit minilibx/libmlx.a
SRC = 		srcs/main.c srcs/functions1.c srcs/functions2.c srcs/functions3.c srcs/functions4.c \
			srcs/functions5.c srcs/ft_read_write.c srcs/ft_draw_1.c srcs/functions6.c srcs/ft_draw_2.c
INC = 		-Iincludes

all: $(NAME)

$(NAME): $(OBJ)
		@echo
		@$(gcc) -o $(NAME) $(INC) $(FRAM) $(SRC)
		@echo "=============================> FDF READY"

clean: 
	rm -rf $(OBJ) clean

fclean: clean
		@rm -f $(NAME) fclean

re: fclean all
