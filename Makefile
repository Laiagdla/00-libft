CFLAGS=-Wall -Werror -Wextra
AR=ar rcs
CC=cc
NAME=test
ARCHIVE=libft.a

HDR=includes/libft.h

SRC=srcs/ft_isalpha.c

OBJ= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(ARCHIVE) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(NAME).c -L. -lft

$(ARCHIVE): $(OBJ)
	$(AR) $@ $^

$(OBJ) : $(SRC) $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(ARCHIVE)

fclean: clean
	rm -f *~ \#*
	rm -f $(OBJ)

re: clean fclean all

.PHONY: all clean fclean re
