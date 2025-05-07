NAME=libft.a
DEP=libft.h
FLAGS=-Wall -Werror -Wextra
SRCS= ft_islpha.c \

OBJS= $(OBJS:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all:

.PHONY
