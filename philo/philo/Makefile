# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 10:38:25 by Jskehan           #+#    #+#              #
#    Updated: 2024/05/03 17:44:03 by Jskehan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes/ -g
SRC = main.c \
		utils.c \
		init.c \
		routine.c \
		routine_parts.c \
		routine_die.c \
		print.c \
		monitor.c \
		forks.c \
		destroy.c \
		threads.c


SRC := $(addprefix src/, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lpthread

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
