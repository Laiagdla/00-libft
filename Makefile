FLAG=-Wall -Werror -Wextra
AR=ar rcs
CC=cc
NAME=test
ARCHIVE=libft.a
HDRS=libft.h
SRCS=ft_isalpha.c
OBJS= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L. $(NAME).c

$(ARCHIVE): $(OBJS)
	$(AR) $@ $^

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *~ \#*

re: all clean fclean

.PHONY: all clean fclean re
