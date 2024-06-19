CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/push_swap.c srcs/push_swap_utils.c srcs/deque.c srcs/rule.c srcs/ruletwo.c srcs/quicksort.c srcs/greedy.c srcs/greedy_utils.c srcs/check_deq.c srcs/three_size_sort.c srcs/mergesort_b.c srcs/print_rule.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = srcs_bonus/push_swap_bonus.c srcs_bonus/push_swap_utils_bonus.c srcs_bonus/deque_bonus.c srcs_bonus/rule_bonus.c srcs_bonus/ruletwo_bonus.c srcs_bonus/quicksort_bonus.c srcs_bonus/check_rule_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INC = -I$(INC_DIR)
LIB = -L$(LIB_DIR1) -lft
LIB_BONUS = -L$(LIB_DIR1) -lft -L$(LIB_DIR2) -lgnl
NAME = push_swap
NAME_BONUS = checker

LIB_DIR1 = libft/
LIB_DIR2 = gnl/
INC_DIR = includes/

RM = rm -rf
TOUCH = touch
MAKE = make

all : $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR1) --silent
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(MAKE) -C $(LIB_DIR1) --silent
	$(MAKE) -C $(LIB_DIR2) --silent
	$(CC) $(CFLAGS) -o  $@ $^ $(LIB_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

clean:
	$(MAKE) -C $(LIB_DIR1) clean --silent
	$(MAKE) -C $(LIB_DIR2) clean --silent
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:
	$(MAKE) clean
	$(MAKE) -C $(LIB_DIR1) fclean --silent
	$(MAKE) -C $(LIB_DIR2) fclean --silent
	$(RM) $(NAME) $(NAME_BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
