# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:50:16 by idunaver          #+#    #+#              #
#    Updated: 2019/07/22 14:15:56 by idunaver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re checker pushswap

OBJDIR = obj
SRCDIR = src
LIBDIR = libft
HEADER = -I ./include
HEADER_LIBFT = -I ./libft/include
FLAGS = -Wall -Wextra -Werror -g

CHECKER = checker
SRC_CHECKER_NAME = checker.c \
				work_with_stack.c \
				push.c \
OBJ_CHECKER_NAME = $(SRC_CHECKER_NAME:.c=.o);
SRC_CHECKER = $(addprefix $(OBJDIR)/, $(SRC_CHECKER_NAME))
OBJ_CHECKER = $(addprefix $(OBJDIR)/, $(OBJ_CHECKER_NAME))

PUSH_SWAP = push_swap
SRC_PUSH_SWAP_NAME = push_swap.c \
				work_with_stack.c
OBJ_PUSH_SWAP_NAME = $(SRC_PUSH_SWAP_NAME:.c=.o);
SRC_PUSH_SWAP = $(addprefix $(OBJDIR)/, $(SRC_PUSH_SWAP_NAME))
OBJ_PUSH_SWAP = $(addprefix $(OBJDIR)/, $(OBJ_PUSH_SWAP_NAME))

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJ_CHECKER)
	@make -C $(LIBDIR)
	@gcc $(FLAGS) $^ -o $@ -Llibft -lft

$(PUSH_SWAP): $(OBJ_PUSH_SWAP)
	@make -C $(LIBDIR)
	@gcc $(FLAGS) $^ -o $@ -Llibft -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@gcc $(FLAGS) $(HEADER_LIBFT) $(HEADER) -o $@ -c $<
	
clean:
	@make clean -C $(LIBDIR)
	@rm -Rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -Rf $(CHECKER) $(PUSH_SWAP)

re: fclean all