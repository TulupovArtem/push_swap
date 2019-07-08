# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idunaver <idunaver@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/08 14:50:16 by idunaver          #+#    #+#              #
#    Updated: 2019/07/08 16:18:04 by idunaver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC_ALL = src/*.c

SRC = $(wildcard $(SRC_ALL))

OBJ = $(SRC:.c=.o)

HEADERS = -I include -I libft/include

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : libft $(OBJ)
	gcc $(OBJ) -o $(NAME) -Llibft -lft


.PHONY: libft
libft:
	make -C libft/

%.o: %.c
	@gcc -c $< -o $@ $(HEADERS)

.PHONY: clean
clean:
	@rm -Rf $(OBJ)

.PHONY: fclean
fclean: clean
	@rm -Rf $(NAME)

.PHONY: re
re: fclean all