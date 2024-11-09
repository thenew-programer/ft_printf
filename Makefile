CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -c

Lib_SRC = ${wildcard libft/*.c}
LIB_OBJ = ${LIB_SRC:.c=.o}

LIB = libft.a

SRCS = ${wildcard src/*.c}
OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

all: ${NAME}

${NAME}:	${OBJS} ${libfd.a}
					${AR} $@ $^

.c.o:
					${CC} ${CFLAGS} $< -o ${<:.c=.o}



clean:
					${RM} *.o

fclean:		clean
					${RM} ${NAME}

re:			fclean	all

.PHONY:	fclean clean all re
