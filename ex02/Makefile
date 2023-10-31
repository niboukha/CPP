CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

NAME = Account

SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.opp)

all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
