CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = Megaphone

SRC = Megaphone.cpp
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
