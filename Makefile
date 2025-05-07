FLAG=-Wall -Werror -Wextra
AR=ar rcs
CC=cc
NAME=libft
ARCHIVE=libft.a
HDRS=libft.h
SRCS=ft_isalpha.c
OBJS= $(SRCS:.c=.o)

$(ARCHIVE): $(OBJS)
	$(AR) $@ $^

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# all: $(NAME)

# $(NAME): $(OBJS)s
# 	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *~ \#*

re: all clean fclean

.PHONY: all clean fclean re
