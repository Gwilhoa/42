# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2022/01/19 16:15:50 by gchatain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c push_swap_utils.c push_swap_display.c basic_function.c tri.c lst_high_low.c

OBJS = ${SRCS:.c=.o}

LIBRARY = libft.a

HEADER = libft.h push_swap.h

NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

%.o : %.c  ${HEADER}
	@${CC} ${CFLAGS} -c $< -o $@
	@printf "$< :"
	@norminette $< | grep -c 'OK!' | sed s/1/✅/ | sed s/0/❌/

$(NAME):	${OBJS}
	@echo ---libft---
	@make -s -C libft
	@cp libft/libft.a .
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY}
	@printf "${NAME}: ✅\n"

all :		${NAME}

clean:
	@${RM} ${OBJS}
	@printf "push_swap : 🗑️\n"
	@make -s -C libft fclean
	@printf "________________\n"

fclean:		clean
	@${RM} ${NAME}
	@${RM} ${LIBRARY}

re: fclean all

.PHONY: all clean fclean re
