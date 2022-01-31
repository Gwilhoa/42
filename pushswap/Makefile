# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2022/01/31 18:32:14 by gchatain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

ERASE		=	\033[2K\r
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLD		=	\033[1m
UNDER		=	\033[4m
SUR			=	\033[7m
END			=	\033[0m

LST_SRCS =   main.c push_swap_utils.c push_swap_display.c basic_function.c tri.c lst_high_low.c
INC = 0
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
			mkdir -p .objects
			${CC} ${CFLAGS} -c $< -o $@
			printf "${ERASE}${BLUE}[BUILD]${END} $<"

${NAME}:	compilation ${OBJS} ${INCLUDES} Makefile compilation
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY}
			echo "${ERASE}${GREEN}[DONE]${END} ${NAME}"

clean:
			${RM} ${OBJS}
			make fclean -C libft
			printf "${RED}[DELETE]${END} *.o"

fclean:	clean
			${RM} -r ${NAME} .objects
			printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:		fclean all

compilation:
	make -C libft
.PHONY:	all clean fclean re compilation

.SILENT:
