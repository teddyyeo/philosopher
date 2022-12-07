# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tayeo <tayeo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 14:57:30 by tayeo             #+#    #+#              #
#    Updated: 2022/12/07 15:41:32 by tayeo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

SRC_PRINTF = ft_printf.c format_str_parser.c put_uint.c put_hex.c basic_utils.c ft_putnbr.c
SRC_UTILS = ft_atoi.c
SRC = $(SRC_PRINTF) $(SRC_UTILS) main.c

OBJ = ${SRC:.c=.o}

FLAG = -Werror -Wall -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $? -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAG) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
