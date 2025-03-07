CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_u.c ft_putstr.c ft_putadd.c ft_puthexa.c ft_calloc.c ft_free.c 
OBJ = ${SRC:.c=.o}
NAME = ultims.a

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean:
	rm -rf ${NAME} ${OBJ}

re: fclean all