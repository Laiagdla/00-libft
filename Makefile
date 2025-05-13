CFLAGS=-I./includes -Wall -Werror -Wextra
AR=ar rcs
CC=cc
NAME=test
ARCHIVE=libft.a

SRC=srcs/ft_isalpha.c \
	srcs/ft_isdigit.c \
	srcs/ft_isalnum.c \
	srcs/ft_isascii.c \
	srcs/ft_isprint.c

OBJ= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(ARCHIVE) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(NAME).c -L. -lft
	@echo "\n///// TESTS /////"
	@./$(NAME)
	@echo "///// T END /////\n"
	@make fclean

$(ARCHIVE): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(ARCHIVE)

fclean: clean
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
