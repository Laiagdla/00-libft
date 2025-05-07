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
	$(CC) $(CFLAGS) -o $@ $^ -L. -lft $(NAME).c

$(ARCHIVE): $(OBJS)
	$(AR) $@ $^

$(OBJS) : $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *~ \#*
	rm -f *.o

re: clean fclean all

.PHONY: all clean fclean re
