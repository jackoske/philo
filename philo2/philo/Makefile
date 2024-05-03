# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 10:38:25 by Jskehan           #+#    #+#              #
#    Updated: 2024/05/03 13:18:43 by Jskehan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes/ -g
SRC = main.c \
		utils.c \
		init.c \
		print.c \
		thread.c \
		routine.c \
		routine_parts.c \
		# simulation.c \


SRC := $(addprefix src/, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lpthread

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
