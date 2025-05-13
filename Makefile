CFLAGS=-I./includes -Wall -Werror -Wextra
AR=ar rcs
CC=cc
NAME=test
ARCHIVE=libft.a

TEST_PRINT=\e[1;34m******* TESTING $< ********\e[0m
TEST_OKEND=\e[1;32m******* ALL OK $< *********\e[0m

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
	srcs/ft_memchr.c \
	srcs/ft_memcmp.c \
	srcs/ft_memcpy.c

OBJ= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(ARCHIVE) $(OBJ)
	@make cleanlog
	@$(CC) $(CFLAGS) -o $@ $(NAME).c -L. -lft >> build.log 2>&1
	@echo "${TEST_PRINT}"
	@./$(NAME)
	@echo "${TEST_OKEND}"
	@make fclean >> build.log 2>&1

$(ARCHIVE): $(OBJ)
	@$(AR) $@ $^ >> build.log 2>&1

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ >> build.log 2>&1

clean:
	@rm -f $(NAME) $(ARCHIVE) >> build.log 2>&1

fclean: clean
	@rm -f $(OBJ) >> build.log 2>&1

re: fclean all

cleanlog:
	@echo "" > build.log

.PHONY: all clean fclean re cleanlog
