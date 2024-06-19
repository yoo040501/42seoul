CC = gcc
CFALGS = -Wall -Wextra -Werror
INC = ./includes/
SRCS = ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_putchar.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
TARGET = libft.a

RM = rm -f
AR = ar rc

all : $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.c.o:
	$(CC) $(CFALGS) -I$(INC) -c -o $@ $<

.PHONY: clean all fclean re
