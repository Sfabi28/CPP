
NAME = phonebook

SRCS = PhoneBook.cpp Contact.cpp main.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all:$(NAME)

$(NAME):
	$(CC) $(SRCS) $(FLAGS) -o $(NAME)

clean:
	@echo "no object to be cleaned"

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

