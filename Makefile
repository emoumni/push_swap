NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_split.c functions.c parsing_tools.c parsing.c push_to_stack_moves.c main.c \
			reverse_rotate_moves.c rotate_moves.c sorting_algo_6up.c sorting_to_five.c \
			sorting_tools.c swap_moves.c tools_for_linked_list.c sorting_up_6_tools.c
OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h

all: $(NAME)


$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

bonus:	all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re