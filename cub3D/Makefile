CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/cub3d.c 					\
		srcs/parsing/check_file.c		\
		srcs/parsing/check_in_file.c	\
		srcs/parsing/check_map.c		\
		srcs/parsing/check_dir_path.c	\
		srcs/parsing/check_color.c		\
		srcs/parsing/get_map.c			\
		srcs/utils/free.c				\
		srcs/utils/init_window.c		\
		srcs/utils/init.c				\
		srcs/utils/print_error.c		\
		srcs/raycasting/cal.c			\
		srcs/raycasting/image.c			\
		srcs/raycasting/key_move.c		\
		srcs/raycasting/key.c			\
		srcs/raycasting/mouse_move.c	\
		srcs/raycasting/mouse.c

SRCSB = srcs_bonus/cub3d.c 						\
		srcs_bonus/parsing/check_file.c			\
		srcs_bonus/parsing/check_in_file.c		\
		srcs_bonus/parsing/check_map.c			\
		srcs_bonus/parsing/check_dir_path.c			\
		srcs_bonus/parsing/check_color.c				\
		srcs_bonus/parsing/get_map.c			\
		srcs_bonus/utils/free.c					\
		srcs_bonus/utils/init_window.c			\
		srcs_bonus/utils/init.c					\
		srcs_bonus/utils/min.c					\
		srcs_bonus/utils/print_error.c			\
		srcs_bonus/raycasting/cal.c				\
		srcs_bonus/raycasting/image.c			\
		srcs_bonus/raycasting/key_move.c		\
		srcs_bonus/raycasting/key.c				\
		srcs_bonus/raycasting/mouse_move.c		\
		srcs_bonus/raycasting/mouse.c			\
		srcs_bonus/minimap/minimap.c			\
		srcs_bonus/minimap/minimap_player.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

INC = -I$(INC_DIR)
MLX_DIR = mlx/

LIB_DIR1 = libft/
LIB_DIR2 = gnl/
INC_DIR = includes/

MLX = -Lmlx/ -lmlx -framework OpenGL -framework Appkit
LIB = -L$(LIB_DIR1) -lft -L$(LIB_DIR2) -lgnl $(MLX)
NAME = cub3D
BONUS = cub3D

RM = rm -rf
TOUCH = touch
MAKE = make

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR) --silent
	$(MAKE) -C $(LIB_DIR1) --silent
	$(MAKE) -C $(LIB_DIR2) --silent
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

bonus : $(OBJSB)
	$(MAKE) -C $(MLX_DIR) --silent
	$(MAKE) -C $(LIB_DIR1) --silent
	$(MAKE) -C $(LIB_DIR2) --silent
	$(CC) $(CFLAGS) -o $(BONUS) $^ $(LIB)
	touch $@

clean:
	$(MAKE) -C $(LIB_DIR1) clean --silent
	$(MAKE) -C $(LIB_DIR2) clean --silent
	$(MAKE) -C $(MLX_DIR) clean --silent
	$(RM) $(OBJS)
	$(RM) $(OBJSB)

fclean:
	$(MAKE) clean
	$(MAKE) -C $(LIB_DIR2) fclean --silent
	$(MAKE) -C $(LIB_DIR1) fclean --silent
	$(RM) $(NAME) bonus $(BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
