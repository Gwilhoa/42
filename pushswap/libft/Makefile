# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 10:35:56 by gchatain          #+#    #+#              #
#    Updated: 2022/01/27 10:51:59 by gchatain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END= 
RED= 
GREEN= 
BLUE= 

LST_SRCS =   ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
ft_tolower.c ft_toupper.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c\
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstmap.c\
ft_printf.c printf_function.c

LST_OBJS = ${LST_SRCS:.c=.o}
SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))
INCLUDES    = includes/libft.h
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
NAME        = libft.a
RM          = rm -f

all:        ${NAME}

.objects/%.o:		sources/%.c ${INCLUDES}
		@mkdir -p .objects
		@${CC} ${CFLAGS} -c $< -o $@
		@echo "${BLUE}[BUILD]${END} $@" | sed s/sources/${NAME}/ && norminette $< | grep -c 'OK!' | sed s/1/✅/ | sed s/0/❌/

${NAME}:	${OBJS} ${INCLUDES} Makefile
			@ar -rcs ${NAME} ${OBJS}
			@echo "${GREEN}[CREATE]${END} ${NAME}"

clean:
			@${RM} ${OBJS}
			@echo "${RED}[DELETE]${END} *.o"

fclean:	clean
			@${RM} -r ${NAME} .objects
			@echo "${RED}[DELETE]${END} ${NAME}"

re:		fclean all

.PHONY:	all clean fclean re
