NAME = converter
SOURCES = $(wildcard ./src/*.cpp)
CC = @c++
CFLAGS = -std=c++98 -pedantic -g -Wall -Wextra -Werror -fsanitize=address,undefined

all:	$(NAME)
$(NAME):	$(SOURCES)
		$(CC) $(CFLAGS) $(^) -o $(@)

clean:
		@rm -f $(wildcard ./src/*.o)

fclean:	clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re