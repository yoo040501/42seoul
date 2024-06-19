CC = gcc
CFALGS = -Wall -Wextra -Werror
INC = ./includes/
SRCS = ./srcs/ft_atoi.c ./srcs/ft_cal.c ./srcs/ft_do_op.c ./srcs/main.c ./srcs/ft_write.c
OBJS = $(SRCS:.c=.o)
TARGET = do-op
RM = rm -f

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFALGS) -o $(TARGET) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -I$(INC) -c -o $@ $<

.PHONY: all clean fclean re
