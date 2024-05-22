# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 13:10:59 by acarpent          #+#    #+#              #
#    Updated: 2024/05/22 12:56:56 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	client.c server.c

OBJS = $(SRCS:%.c=%.o)

NAME = minitalk

CC = cc

all: server client 

%.o:	%.c
			${CC} ${CFLAGS} -Ilibft -Ift_printf -c $? -o $@

server:		server.o
			@make -C libft
			@make -C ft_printf
			${CC} ${CFLAGS} $? -Llibft -lft -Lft_printf -lftprintf -o server

client:		client.o
			@make -C libft
			@make -C ft_printf
			${CC} ${CFLAGS} $? -Llibft -lft -Lft_printf -lftprintf -o client

CFLAGS = -Wall -Werror -Wextra -g3

libft:		make -C libft
	
printf:		make -C ft_printf

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f *.o
		make clean -C libft 
		make clean -C ft_printf

fclean: clean
		rm -f $(NAME) server client

re: fclean all

.PHONY: all clean fclean re libft ft_printf