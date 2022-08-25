NAME = libft.a
FLAGS = -Wall -Wextra -Werror
HEADERS = ./
SRC = *.c
OFILES  = *.o 

.PHONY	:	all clean fclean re

all		: $(NAME)

$(NAME)	:
		@gcc $(FLAGS) -c $(SRC) -I $(HEADERS)
		@ar rc $(NAME) $(OFILES)
clean	:
		@rm -rf $(OFILES) 

fclean	: clean
		@rm -rf $(NAME)

re		: fclean all