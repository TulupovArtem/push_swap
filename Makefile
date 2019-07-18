# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:50:16 by idunaver          #+#    #+#              #
#    Updated: 2019/07/18 13:42:23 by idunaver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
SRC_CHECKER = src/checker.c
OBJ_CHECKER = $(SRC_CHECKER:%.c=%.o)

PUSH_SWAP = push_swap
SRC_PUSH_SWAP = src/push_swap.c
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:%.c=%.o)

HEADER = -I include -I libft/include
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

.PHONY: all libft clean fclean re checker pushswap

all: checker pushswap
	
checker: libft
	@gcc -c $(SRC_CHECKER) -o $(OBJ_CHECKER) $(HEADER)
	@gcc $(FLAGS) $(OBJ_CHECKER) -L libft -o $(CHECKER) -g

pushswap: libft
	@gcc -c $(SRC_PUSH_SWAP) -o $(OBJ_PUSH_SWAP) $(HEADER)
	@gcc $(FLAGS) $(OBJ_PUSH_SWAP) -L libft -o $(PUSH_SWAP) -g

libft:
	@make -C libft/

clean:
	@make clean -C libft/
	@rm -Rf $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)

fclean: clean
	@make fclean -C libft/
	@rm -Rf $(PUSH_SWAP) $(CHECKER)

re: fclean all