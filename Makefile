CFLAGS=-I./includes -Wall -Werror -Wextra
AR=ar rcs
CC=cc
NAME=test
ARCHIVE=libft.a

TEST_PRINT=\e[1;34m******* TESTING $< ********\e[0m
TEST_END=\e[1;32m******* ALL OK $< ********\e[0m

SRC=srcs/ft_isalpha.c \
	srcs/ft_isdigit.c \
	srcs/ft_isalnum.c \
	srcs/ft_isascii.c \
	srcs/ft_isprint.c \
	srcs/ft_strlen.c \
	srcs/ft_toupper.c \
	srcs/ft_tolower.c \
	srcs/ft_strchr.c \
	srcs/ft_strrchr.c \
	srcs/ft_memset.c \
	srcs/ft_memchr.c

OBJ= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(ARCHIVE) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(NAME).c -L. -lft
	@echo "\n${TEST_PRINT}"
	@./$(NAME)
	@echo "${TEST_END} \n"
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
