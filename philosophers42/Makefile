# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jskehan <jskehan@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:03:36 by zmoussam          #+#    #+#              #
#    Updated: 2024/05/09 15:37:38 by Jskehan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philos
BONUS_NAME = philos_bonus
SRC = ./philo/main.c ./philo/init_philo_and_mutex.c ./philo/validation.c ./philo/routine.c ./philo/utils.c ./philo/routine_func.c
			
BNS_SRC = ./philo_bonus/main.c ./philo_bonus/create_philo.c ./philo_bonus/utils.c ./philo_bonus/validation.c ./philo_bonus/routine.c ./philo_bonus/routine_func.c
OBJ = ${SRC:.c=.o}
BOBJ = ${BNS_SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS =  -Wall -Wextra -Werror 

all: $(NAME)

	
%.o:%.c *.h
	@$(CC) -c  $(CFLAGS) $<
	
$(NAME): $(OBJ)  ./philo/philosophers.h
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

bonus: $(BONUS_NAME)
 
$(BONUS_NAME) : $(BOBJ) ./philo_bonus/philo_bonus.h
	@$(CC) $(CFLAGS) $(BNS_SRC) -o $(BONUS_NAME)
	@echo "Compiling Successfull"
	
	
clean:
	@$(RM) $(OBJ) $(BOBJ)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "Clear"

re: fclean all