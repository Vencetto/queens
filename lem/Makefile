# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzomber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 18:34:19 by vzomber           #+#    #+#              #
#    Updated: 2018/10/05 16:41:12 by vzomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC  =	src/main.c src/additional.c src/parse.c src/checking.c src/create.c \
		src/create_helper.c	src/algorithm.c src/queue.c src/ways.c src/go_ants.c \
		src/info.c src/go_ants_2.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
SEGF = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	#@make -C ./libft
	@gcc $(FLAGS) $(OBJ) -L libft/ -lft -o $(NAME) $(SEGF)
	@echo "\033[32m\033[36m  lem-in \033[32mdone\033[0m"

%.o: %.c includes/lem_in.h
	@gcc -c $< -o $@ $(FLAGS) -I includes/ -I libft/includes	

clean:
	#@make clean -C ./libft
	@rm -f $(OBJ)

fclean: clean 
	#@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all
