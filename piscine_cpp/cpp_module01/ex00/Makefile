# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 10:35:56 by gchatain          #+#    #+#              #
#    Updated: 2022/07/12 13:32:35 by gchatain         ###   ########lyon.fr    #
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

NAME		:= ex00
FLAGS		:= -std=c++98 -Werror -Wall -Wextra -g3
CC			:= g++


LST_SRCS	:= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp

LST_OBJS		:= $(LST_SRCS:.cpp=.o)
OBJS			:= $(addprefix .objects/,$(LST_OBJS))
SRCS			:= $(addprefix sources/,$(LST_SRCS))

INCLUDES		:= includes/
DIR_INCLUDES	:= $(sort $(addprefix -I, $(dir $(INCLUDES))))


all: $(NAME)

.objects/%.o:	sources/%.cpp ${INCLUDES} | .objects
			${CC} ${FLAGS} -c $< -o $@ ${DIR_INCLUDES}
			printf "${ERASE}${BLUE}[BUILD]${END} $<"

$(NAME): $(LIBFT) $(OBJS) Makefile $(INCLUDES)
		${CC} ${FLAGS} -o ${NAME} ${OBJS} ${DIR_INCLUDES}

clean:
			${RM} ${OBJS}
			printf "${RED}[DELETE]${END} directory .objects"

fclean:	clean
			${RM} -r ${NAME} .objects
			printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:			fclean all

.objects:
			mkdir -p .objects

.PHONY: all re fclean clean compilation
.SILENT:
