NAME = DiamondAttack
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
OPTION = -o

all: $(NAME)

$(NAME):
		$(CC) $(OPTION) $(NAME) $(FLAG) $(SRC)

clean: 

fclean: clean
		rm -f $(NAME)

re:		fclean all

bonus:	all

.PHONY: all bonus clean fclean re