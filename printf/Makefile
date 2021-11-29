# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 17:49:48 by gchatain          #+#    #+#              #
#    Updated: 2021/11/29 10:22:30 by gchatain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_changebase.c function_printf.c ft_strlen.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_function_unsigned.c

OBJS = ${SRCS:.c=.o}

HEADER = ft_printf.h

NAME = libftprintf.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o : %.c  ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

$(NAME):	${OBJS}
	ar -rcs ${NAME} ${OBJS}

all :		${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
