# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:38:57 by gchatain          #+#    #+#              #
#    Updated: 2022/07/06 10:48:46 by gchatain         ###   ########lyon.fr    #
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

NAME		:= megaphone
FLAGS		:= -std=c++98 -Werror -Wall -Wextra -g3
CC			:= g++


LST_SRCS	:= phonebook.cpp

LST_OBJS		:= $(LST_SRCS:.cpp=.o)
OBJS			:= $(addprefix .objects/,$(LST_OBJS))
SRCS			:= $(addprefix sources/,$(LST_SRCS))

INCLUDES		:= 
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
