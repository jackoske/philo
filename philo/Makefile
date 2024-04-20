# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jskehan <jskehan@student.42Berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 10:38:25 by Jskehan           #+#    #+#              #
#    Updated: 2024/04/20 12:06:28 by Jskehan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes/
SRC = main.c \
		utils.c \
		init.c \
		utils.c \


SRC := $(addprefix src/, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lpthread

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
