CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = megaphone

RM = rm -rf
TOUCH = touch
MAKE = make

all : $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
