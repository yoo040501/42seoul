CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/pipex.c srcs/pipex_util.c srcs/pipex_cmd.c
SRCS_BONUS = srcs_bonus/pipex_bonus.c srcs_bonus/pipex_util_bonus.c srcs_bonus/pipex_heredoc_bonus.c srcs_bonus/pipex_pipe_bonus.c srcs_bonus/pipex_cmd_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INC = -I$(INC_DIR)
LIB = -L$(LIB_DIR1) -lft
LIB_BONUS = $(LIB) -L$(LIB_DIR2) -lgnl
NAME = pipex

LIB_DIR1 = libft/
LIB_DIR2 = gnl/
INC_DIR = includes/

RM = rm -rf
TOUCH = touch
MAKE = make

all : $(NAME)
bonus : make_bonus

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR1) --silent
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

make_bonus: $(OBJS_BONUS)
	$(MAKE) -C $(LIB_DIR1) --silent
	$(MAKE) -C $(LIB_DIR2) --silent
	$(CC) $(CFALGS) -o $(NAME) $^ $(LIB_BONUS)
	$(TOUCH) .make_bonus

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

clean:
	$(MAKE) -C $(LIB_DIR1) clean --silent
	$(MAKE) -C $(LIB_DIR2) clean --silent
	$(RM) $(OBJS) $(OBJS_BONUS) .make_bonus

fclean:
	$(MAKE) clean
	$(MAKE) -C $(LIB_DIR2) fclean --silent
	$(MAKE) -C $(LIB_DIR1) fclean --silent
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
