# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 14:34:56 by ramory-l          #+#    #+#              #
#    Updated: 2019/09/13 19:15:15 by idunaver         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_SEARCH = src/*.c \
			 src/ft_printf/src/*.c \
			 src/ft_printf/src/support/*.c \
			 src/ft_printf/src/double/*.c \

SRC = $(wildcard $(SRC_SEARCH))

OBJ = $(SRC:.c=.o)

HEADERS = -I include -I src/ft_printf/include

IMFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

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
