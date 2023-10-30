CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

NAME = phonebook

SRC = phonebook.cpp contact.cpp main.cpp

OBJ = $(SRC:.cpp=.opp)

# HEADER = phonebook.hpp contact.hpp

all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
