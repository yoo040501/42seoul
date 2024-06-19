CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c pf_hex.c pf_int.c pf_string.c pf_ptr.c pf_uint.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

RM = rm -f
AR = ar rc
TOUCH = touch
MAKE = make

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
