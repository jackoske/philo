# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:03:36 by zmoussam          #+#    #+#              #
#    Updated: 2024/05/09 17:04:10 by Jskehan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philos
SRC = ./philo/main.c \
	./philo/init_philo_and_mutex.c \
	./philo/validation.c \
	./philo/routine.c \
	./philo/utils.c \
	./philo/routine_func.c
			
OBJ = ${SRC:.c=.o}

CC = cc
RM = rm -rf
CFLAGS =  -Wall -Wextra -Werror 

all: $(NAME)

	
%.o:%.c *.h
	@$(CC) -c  $(CFLAGS) $<
	
$(NAME): $(OBJ)  ./includes/philosophers.h
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

clean:
	@$(RM) $(OBJ) $(BOBJ)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "Clear"

re: fclean all