CC = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror #-fsanitize=address -g3

NAME = ex01
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp

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
