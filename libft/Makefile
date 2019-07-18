NAME = libft.a

SRC_SEARCH = src/*.c

SRC = $(wildcard $(SRC_SEARCH))

OBJ = $(SRC:.c=.o)

INCLUDES = -I include

FLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS) $(INCLUDES)

.PHONY: clean
clean:
	@rm -rf $(OBJ)

.PHONY: fclean
fclean:	clean
	@rm -rf $(NAME)

.PHONY: re
re: fclean all
