# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 13:10:59 by acarpent          #+#    #+#              #
#    Updated: 2024/05/06 12:55:23 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	client.c server.c minitalk_utils.c

OBJS = $(SRCS:%.c=%.o)

NAME = minitalk

CC = cc

%.o:	%.c
			${CC} ${CFLAGS} -Ift_printf -c $? -o $@

server:		server.o
			@make -C ft_printf
			${CC} ${CFLAGS} $? -Lft_printf -lftprintf -o server

client:		client.o
			@make -C ft_printf
			${CC} ${CFLAGS} $? -Lft_printf -lftprintf -o client

CFLAGS = -Wall -Werror -Wextra

printf:		make -C ft_printf

all: server client

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f *.o
		make clean -C ft_printf

fclean: clean
		rm -f $(NAME) server client

re: fclean all

.PHONY: all clean fclean re ft_printf