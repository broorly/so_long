NAME	=	so_long

SRCS	=	src/*.c so_long.c

OBJCT	=	${SRCS:.c=.o}

FLAGES	=	-lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

CC		=	gcc -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(FLAGES) $(SRCS) -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY:		all clean fclean re bonus