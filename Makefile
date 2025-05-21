CFLAGS=-I./includes -g -Wall -Werror -Wextra
AR=ar rcs
CC=cc
NAME=libft
ARCHIVE=libft.a

TEST_PRINT=\e[1;34m******* TESTING $< ********\e[0m
TEST_OKEND=\e[1;34m******* ALL OK $< *********\e[0m

SRC=srcs/ft_isalpha.c \
	srcs/ft_isdigit.c \
	srcs/ft_isalnum.c \
	srcs/ft_isascii.c \
	srcs/ft_isprint.c \
	srcs/ft_toupper.c \
	srcs/ft_tolower.c \
	srcs/ft_memset.c \
	srcs/ft_memchr.c \
	srcs/ft_memcmp.c \
	srcs/ft_memcpy.c \
	srcs/ft_memmove.c \
	srcs/ft_strchr.c \
	srcs/ft_strrchr.c \
	srcs/ft_strlen.c \
	srcs/ft_strncmp.c \
	srcs/ft_strnstr.c \
	srcs/ft_strlcpy.c \
	srcs/ft_strlcat.c \
	srcs/ft_bzero.c \
	srcs/ft_atoi.c \
	srcs/ft_strdup.c \
	srcs/ft_calloc.c \
	srcs/ft_substr.c \
	srcs/ft_strjoin.c \
	srcs/ft_strtrim.c \
	srcs/ft_split.c \
	srcs/ft_itoa.c \
	srcs/ft_strmapi.c \
	srcs/ft_striteri.c \
	srcs/ft_putchar_fd.c \
	srcs/ft_putstr_fd.c \
	srcs/ft_putendl_fd.c \
	srcs/ft_putnbr_fd.c

OBJ= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(ARCHIVE) $(OBJ)
	@make cleanlog
	@$(CC) $(CFLAGS) -o $@ $(NAME).c -L. -lft -lbsd >> build.log
	@echo "${TEST_PRINT}"
	@./$(NAME)
	@echo "${TEST_OKEND}"
	# @make fclean >> build.log

$(ARCHIVE): $(OBJ)
	@$(AR) $@ $^ >> build.log

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ >> build.log

clean:
	@rm -f $(NAME) $(ARCHIVE) >> build.log 2>&1
	@rm -f $(NAME).so

fclean: clean
	@rm -f $(OBJ) >> build.log 2>&1

re: fclean all

cleanlog:
	@echo "" > build.log

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re cleanlog so
