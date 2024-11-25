CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/so_long.c srcs/check_map.c srcs/move.c srcs/utils.c srcs/dfs.c
OBJS = $(SRCS:.c=.o)

INC = -I$(INC_DIR)
LIB = -L$(LIB_DIR1) -lft -L$(LIB_DIR2) -lgnl

LIB_DIR1 = libft/
LIB_DIR2 = gnl/
INC_DIR = includes/
MLX = -lmlx -framework OpenGL -framework Appkit
NAME = so_long

RM = rm -rf
TOUCH = touch
MAKE = make

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR1) --silent
	$(MAKE) -C $(LIB_DIR2) --silent
	$(CC) $(CFLAGS) $(MLX) -o $@ $^ $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	$(MAKE) -C $(LIB_DIR1) clean --silent
	$(MAKE) -C $(LIB_DIR2) clean --silent
	$(RM) $(OBJS)

fclean:
	$(MAKE) clean
	$(MAKE) -C $(LIB_DIR2) fclean --silent
	$(MAKE) -C $(LIB_DIR1) fclean --silent
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
