# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2021/12/18 11:09:13 by gchatain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = stack_function.c push_swap.c

OBJS = ${SRCS:.c=.o}

LIBRARY = libft.a

HEADER = libft.h push_swap.h

NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o : %.c  ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

$(NAME):	${OBJS}
	make -C libft
	cp libft/libft.a .
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY}

all :		${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}
	make -C libft fclean

fclean:		clean
	${RM} ${NAME}
	${RM} ${LIBRARY}
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
