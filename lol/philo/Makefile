# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 17:23:00 by Jskehan           #+#    #+#              #
#    Updated: 2024/05/09 17:23:01 by Jskehan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC = main.c \
	init.c \
	validation.c \
	routine.c \
	utils.c \
	routine_func.c

OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRC))

CC = cc
RM = rm -rf
CFLAGS =  -Wall -Wextra -Werror 

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c  $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling Successful"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Object Files Removed Successfully"

fclean: clean
	@$(RM) $(NAME)
	@echo "Clear"

re: fclean all