CPP = c++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 
#CFLAGS = -g -fsanitize=address
SRCS =	main.cpp		\
		ClapTrap.cpp	\
		ScavTrap.cpp	\
		FragTrap.cpp	\
		DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = ex03

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
