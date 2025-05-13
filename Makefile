CFLAGS=-I./includes -Wall -Werror -Wextra
AR=ar rcs
CC=cc
NAME=test
ARCHIVE=libft.a

SRC=srcs/ft_isalpha.c

OBJ= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(ARCHIVE) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(NAME).c -L. -lft

$(ARCHIVE): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(ARCHIVE)

fclean: clean
	rm -f $(OBJ)

re: clean fclean all

.PHONY: all clean fclean re

