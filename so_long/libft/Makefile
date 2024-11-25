CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = libft.h
SRCS_PART1 = ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
SRCS_PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS = $(SRCS_PART1) $(SRCS_PART2)
OBJS = $(SRCS:.c=.o)

NAME = libft.a

RM = rm -f
AR = ar rc
TOUCH = touch
MAKE = make

all: $(NAME)

$(NAME): make_man

make_man: $(OBJS)
	$(AR) $(NAME) $^
	$(TOUCH) make_man

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	$(RM) make_man

re:
	$(MAKE) fclean
	$(MAKE) all

%.o : %.c
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

.PHONY: all clean fclean re bonus
