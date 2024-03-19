NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


# Path: Sources

SRC = check_args_utils.c pa_pb.c push_swap.c ra_rb_rr.c rra_rrb_rrr.c sa_sb_ss.c  ronin_algo.c sort_less_than_5.c
INCLUDES = push_swap.h
INCLUDES_BONUS = checker.h
SRC_BONUS = checker.c check_args_utils.c checker_utils1.c checker_utils2.c
# Path: Objects

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
# Path: Libft

LIBFT = libft.a

# Path: Rules

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/$(LIBFT)

bonus: $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C libft

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) ./libft/$(LIBFT)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus

# Path: Dependenci