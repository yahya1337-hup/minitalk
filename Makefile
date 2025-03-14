CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS1 = help.c client.c
SRCS2 = help.c server.c

OBJS1 = ${SRCS1:.c=.o}
OBJS2 = ${SRCS2:.c=.o}

NAME1 = client
NAME2 = server

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME1} ${NAME2}

${NAME1}: ${OBJS1}
	${CC}  ${CFLAGS} ${OBJS1} -o ${NAME1}

${NAME2}: ${OBJS2}
	${CC}  ${CFLAGS} ${OBJS2} -o ${NAME2}

clean:
	@${RM} ${OBJS2} ${OBJS1}

fclean: clean
	@${RM} ${NAME1} ${NAME2}

re: fclean all

.PHONY: all fclean re clean