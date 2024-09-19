CPP = c++
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 
SRCS =	main.cpp		\
		AMateria.cpp	\
		Character.cpp	\
		Cure.cpp		\
		Ice.cpp			\
		MateriaSource.cpp
		
OBJS = $(SRCS:.cpp=.o)

NAME = Interface

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
