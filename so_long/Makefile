# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2022/03/16 12:52:21 by gchatain         ###   ########lyon.fr    #
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

LST_SRCS =  main.c get_next_line_bonus.c get_next_line_utils_bonus.c fen_disp.c\
			moves.c init.c
INC = 0
LST_OBJS = ${LST_SRCS:.c=.o}
LIBRARY = libft/libft.a mlx/libmlx.a
SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))
INCLUDES    = includes/get_next_line_bonus.h libft/includes/libft.h includes/so_long.h mlx/mlx.h
DIR_INCLUDES = $(sort $(addprefix -I, $(dir $(INCLUDES))))
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
NAME        = so_long
RM          = rm -f
LIBX        = -I /usr/X11/include -g -L ./mlx -l mlx -framework OpenGL -framework AppKit
NORM        = $(shell norminette sources | grep -c 'Error!')

ifeq ($(NORM), 0)
	NORM_RET = "${ERASE}${GREEN}[DONE]${END} ${NAME}"
else
	NORM_RET = "${ERASE}${RED}[NORM]${END} ${NAME}"
endif

all:        ${NAME}

.objects/%.o:		sources/%.c | .objects
			${CC} ${CFLAGS} -c $< -o $@ $(DIR_INCLUDES)
			printf "${ERASE}${BLUE}[BUILD]${END} $<"

${NAME}:	${OBJS} ${INCLUDES} Makefile libft/libft.a mlx/libmlx.a
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY} ${LIBX} $(DIR_INCLUDES)
			printf $(NORM_RET)

clean:
			${RM} ${OBJS}
			${RM} -rf a.out.dSYM
			make fclean -s -C libft
			make clean -s -C mlx
			printf "${RED}[DELETE]${END} *.o"

fclean:	clean
			${RM} -r ${NAME} .objects
			printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:		fclean all

libft/libft.a:
	make -s -C libft

mlx/libmlx.a:
	make -s -C mlx

.objects:
			mkdir -p .objects
.PHONY:	all clean fclean re

.SILENT:
