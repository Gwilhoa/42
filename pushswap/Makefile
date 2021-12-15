# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2021/12/15 12:12:31 by gchatain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c

OBJS = ${SRCS:.c=.o}

HEADER = libft.h

NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o : %.c  ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

$(NAME):	${OBJS}
	${CC} ${CFLAGS} ${NAME} ${OBJS}

all :		${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
