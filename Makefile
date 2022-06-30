SRC		= ft_printf.c ft_printf_utils.c ft_printf_utils2.c	

OBJS	= ${SRC:.c=.o}

NAME	= libftprintf.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS} 

all:		$(NAME)

clean:
			rm -f ${OBJS} 

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re 
