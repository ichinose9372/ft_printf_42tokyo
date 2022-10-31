NAME = libftprintf.a

SRCS =	ft_putchar.c	\
		ft_putstr.c		\
		ft_putnbr.c		\
		ft_puthex.c		\
		ft_putadrs.c	\
		ft_printf.c		\

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all : ${NAME}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	${RM} ${OBJS}

fclean :
	${RM} ${NAME} ${OBJS}

re : fclean all

.PHONY : all clean fclean
