# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 10:38:25 by Jskehan           #+#    #+#              #
#    Updated: 2024/04/22 20:13:14 by Jskehan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes/ -g
SRC = main.c \
		utils.c \
		init.c \
		simulation.c \
		routine.c \
		routine_die.c \
		print.c \
		monitor.c \


SRC := $(addprefix src/, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lpthread

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
