# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 10:35:56 by gchatain          #+#    #+#              #
#    Updated: 2022/04/10 19:34:27 by gchatain         ###   ########.fr        #
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

SRCS =   megaphone.cpp
CC          = g++
CFLAGS      = -std= c++98 -Wall -Wextra -Werror
NAME        = megaphone
RM          = rm -f

all:        ${NAME}


${NAME}:	${SRCS} ${INCLUDES} Makefile
		$(CC) $(FLAGS) $(NAME).cpp -o $(NAME)
		printf "${ERASE}${GREEN}[DONE]${END} ${NAME}\n"

clean:
		${RM} ${NAME}
		printf "${RED}[DELETE]${END} objects directory"

fclean:	clean
		${RM} -r ${NAME}
		printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:		fclean all


.PHONY:	all clean fclean re

.SILENT:
