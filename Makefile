NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_split.c functions.c parsing_tools.c parsing.c push_to_stack_moves.c main.c \
			reverse_rotate_moves.c rotate_moves.c sorting_algo_6up.c sorting_to_five.c \
			sorting_tools.c swap_moves.c tools_for_linked_list.c sorting_up_6_tools.c
Bonus_srcs = ft_split.c functions.c parsing.c reverse_rotate_moves.c rotate_moves.c \
				swap_moves.c push_to_stack_moves.c get_next_line.c parsing_tools.c push_swap_bonus.c \
				tools_for_linked_list.c functions2.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(Bonus_srcs:.c=.o)
INCLUDE = push_swap.h
Bonus_INCLUDE = /push_swap_bonus.h
NAME_BONUS = checker

all: $(NAME)

bonus : ${Bonus_srcs}

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(NAME_BONUS): $(OBJ_BONUS) $(Bonus_INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re