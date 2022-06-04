# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 18:15:45 by oqatim            #+#    #+#              #
#    Updated: 2022/04/22 16:39:34 by oqatim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = so_long
NAME_B = so_long_bns

FRAME = -lmlx -framework OpenGL -framework AppKit

SRC = mandatory/get_next_line.c  mandatory/get_next_line_utils.c mandatory/parsing_map.c mandatory/so_long_utils.c mandatory/print_map.c mandatory/mouvement.c
SRC_BONUS = bonus/get_next_line.c  bonus/get_next_line_utils.c bonus/parsing_map_bns.c bonus/so_long_utils_bns.c bonus/print_map_bns.c bonus/mouvement_bns.c bonus/ft_itoa.c

HDR = mandatory/so_long.h
HDR_BONUS = bonus/so_long_bns.h

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ) $(HDR)
	cc $(CFLAGS) $(FRAME) $(OBJ) -o $(NAME)

$(NAME_B) : $(OBJ_BONUS) $(HDR_BONUS)
	cc $(CFLAGS) $(FRAME) $(OBJ_BONUS) -o $(NAME_B)

bonus : $(NAME_B)

clean : 
	rm -rf  $(OBJ) $(OBJ_BONUS) 

fclean : clean
	rm -rf $(NAME) $(NAME_B)

re : fclean all bonus