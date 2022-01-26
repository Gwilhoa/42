# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2022/01/26 15:47:22 by gchatain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m

LST_SRCS =   main.c push_swap_utils.c push_swap_display.c basic_function.c tri.c lst_high_low.c

LST_OBJS = ${LST_SRCS:.c=.o}
LIBRARY = libft/libft.a
SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))
INCLUDES    = includes/libft.h includes/push_swap.h
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
NAME        = push_swap
RM          = rm -f

all:        ${NAME}

.objects/%.o:		sources/%.c ${INCLUDES}
		@mkdir -p .objects
		@${CC} ${CFLAGS} -c $< -o $@
		@echo "${BLUE}[BUILD]${END} $<" | sed s/sources/${NAME}/ && norminette $< | grep -c 'OK!' | sed s/1/✅/ | sed s/0/❌/

${NAME}:	${OBJS} ${INCLUDES} Makefile
			@make -C libft
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY}
			@echo "${GREEN}[CREATE]${END} ${NAME}"

clean:
			@${RM} ${OBJS}
			@make fclean -C libft
			@echo "${RED}[DELETE]${END} *.o"

fclean:	clean
			@${RM} -r ${NAME} .objects
			@echo "${RED}[DELETE]${END} ${NAME}"

re:		fclean all

.PHONY:	all clean fclean re
