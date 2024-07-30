CC = cc
#CFLAGS = -g -fsanitize=address
#CFLAGS = -g -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/philo.c \
       srcs/main.c \
	   srcs/init.c \
	   srcs/check.c \
	   srcs/utils.c
OBJS = $(SRCS:.c=.o)

INC = -I$(INC_DIR)
INC_DIR = include/
NAME = philo

RM = rm -rf
TOUCH = touch
MAKE = make

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)

clean:
	$(RM) $(OBJS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
