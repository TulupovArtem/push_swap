# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:50:16 by idunaver          #+#    #+#              #
#    Updated: 2019/07/19 18:41:36 by idunaver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
SRC_CHECKER = src/checker.c src/work_with_stack.c
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
	@gcc $(FLAGS) $(OBJ_CHECKER) -L libft/ -lft -o $(CHECKER) -g

pushswap: libft
	@gcc -c $(SRC_PUSH_SWAP) -o $(OBJ_PUSH_SWAP) $(HEADER)
	@gcc $(FLAGS) $(OBJ_PUSH_SWAP) -L libft/ -lft -o $(PUSH_SWAP) -g

libft:
	@make -C libft/

### Rules for tests ###

test_checker:
	@rm -Rf $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)
	@rm -Rf $(PUSH_SWAP) $(CHECKER)
	@gcc -c $(SRC_CHECKER) -o $(OBJ_CHECKER) $(HEADER)
	@gcc $(FLAGS) $(OBJ_CHECKER) -L libft/ -lft -o $(CHECKER) -g

test_checker_push_swap:
	@rm -Rf $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)
	@rm -Rf $(PUSH_SWAP) $(CHECKER)
	@gcc -c $(SRC_CHECKER) -o $(OBJ_CHECKER) $(HEADER)
	@gcc $(FLAGS) $(OBJ_CHECKER) -L libft/ -lft -o $(CHECKER) -g

#######################

clean:
	@make clean -C libft/
	@rm -Rf $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)

fclean: clean
	@make fclean -C libft/
	@rm -Rf $(PUSH_SWAP) $(CHECKER)

re: fclean all