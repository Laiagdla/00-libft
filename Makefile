CFLAGS	=	-I. -g -Wall -Werror -Wextra
AR		=	ar rcs
CC		=	cc
RM		=	rm -rf
NAME	=	libft.a

SRC 	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_memset.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strlen.c \
			ft_strncmp.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_bzero.c \
			ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c

OBJ		=	$(addprefix build/,$(SRC:.c=.o))
OBJBONUS=	$(addprefix build/,$(SRC:.c=.o)) $(addprefix build/,$(BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

bonus: $(OBJBONUS)
	$(AR) libft.a $^

build:
	mkdir -p build

build/%.o:	%.c build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) build

fclean: clean
	$(RM) $(NAME)

re: fclean all

cleanlog:
	echo "" > build.log

# so:
# 	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
# 	gcc -nostartfiles -shared -o libft.so $(OBJ)

TEST_PRINT=\\e[1;34m******* TESTING $< ********\\e[0m
TEST_OKEND=\\e[1;34m******* ALL OK $< *********\\e[0m

test: bonus $(OBJBONUS)
	@$(CC) $(CFLAGS) libft.c -o libft -L. -lft -lbsd -I.
	@echo "${TEST_PRINT}"
	@./libft
	@echo "${TEST_OKEND}"

# downloadtest:
# 	@if [ ! -L libft.c ]; then \
# 	wget -O libft.c https://github.com/Laiagdla/testmain/raw/refs/heads/main/libft.c >> build.log 2>&1; \
# 	fi

.PHONY: all clean fclean re cleanlog
