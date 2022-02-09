# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2022/02/09 18:46:39 by gchatain         ###   ########lyon.fr    #
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

LST_SRCS_SRV =   main.c
LST_OBJS_SRV = ${LST_SRCS_SRV:.c=.o}
SRCS_SRV = $(addprefix sources/,$(LST_SRCS_SRV))
OBJS_SRV = $(addprefix .objects/,$(LST_OBJS_SRV))


LST_SRCS_CLT =
LST_OBJS_CLT = ${LST_SRCS_SRV:.c=.o}
SRCS_CLT = $(addprefix sources/,$(LST_SRCS_CLT))
OBJS_CLT = $(addprefix .objects/,$(LST_OBJS_SRV))


INCLUDES    = includes/minitalk.h libft/includes/libft.h
DIR_INCLUDES = $(sort $(addprefix -I, $(dir $(INCLUDES))))
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
NORM        = $(shell norminette sources | grep -c 'Error!')

ifeq ($(NORM), 0)
	NORM_RET = "${ERASE}${GREEN}[DONE]${END} minitalk"
else
	NORM_RET = "${ERASE}${RED}[NORM]${END} minitalk"
endif
all:        server client

.objects/%.o:	sources/%.c ${INCLUDES} | .objects
			${CC} ${CFLAGS} -c $< -o $@ ${DIR_INCLUDES}
			printf "${ERASE}${BLUE}[BUILD]${END} $<"

server:	${OBJS_SRV} ${INCLUDES} Makefile libft/libft.a 
			${CC} ${CFLAGS} -o server ${OBJS_SRV} ${DIR_INCLUDES} libft/libft.a
			printf $(NORM_RET)

client:	${OBJS_SLT} ${INCLUDES} Makefile libft/libft.a 
			${CC} ${CFLAGS} -o client ${OBJS} ${DIR_INCLUDES} libft/libft.a
			printf $(NORM_RET)

clean:
			${RM} ${OBJS}
			printf "${RED}[DELETE]${END} directory .objects"
libft/libft.a:
	make -s -C libft

fclean:	clean
			${RM} -r ${NAME} .objects
			make fclean -s -C libft
			printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:			fclean all

.objects:
			mkdir -p .objects

.PHONY:	all clean fclean re compilation

.SILENT: