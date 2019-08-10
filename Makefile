# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhamid <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 15:52:41 by nhamid            #+#    #+#              #
#    Updated: 2019/08/10 13:09:03 by nhamid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
LIBFT = libft/libft.a
CFLAGS = gcc -Wall -Wextra -Werror
SRC = ft_free_obj.c ft_calcule.c ft_file2.c vectors.c ft_file0.c ft_file3.c ft_file7.c ft_file1.c ft_file8.c main.c ft_file9.c maping.c vect_check.c stock_obj.c obj_check.c errors.c cam_check.c check_tools.c parse_file.c filereader.c light_check.c stock_scene.c stock_obj2.c ft_norm.c
SRCO = $(SRC:.c=.o)
INC = -I libft/includes/ -I ./
INC_SRC = libft/includes/libft.h  rtparse.h rtv1.h
INCLUDE = ./minilibx/mlx.h
LIBSNFRAMES = ./minilibx -lmlx -framework OpenGL -framework Appkit
all : $(NAME)

$(NAME) : $(SRCO) $(LIBFT)
	$(CFLAGS) $(INC) -o $@ $(SRCO) $(LIBFT) -I $(INCLUDE) -L $(LIBSNFRAMES)

$(LIBFT) :
	make -C libft

$(SRCO) : %.o: %.c $(INC_SRC)
	$(CFLAGS) -c $< $(INC)

clean :
	rm -rf $(SRCO)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re : fclean all
