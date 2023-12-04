CC = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow -fsanitize=address -g3

NAME = ClapTrap

SRC = ClapTrap.cpp FragTrap.cpp main.cpp  DiamondTrap.cpp ScavTrap.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp %.hpp
	$(CC) $(CXXFLAGS) -c $<
	
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re

