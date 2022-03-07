# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 13:56:27 by gchatain          #+#    #+#              #
#    Updated: 2022/03/07 16:56:57 by gchatain         ###   ########lyon.fr    #
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

NAME		:= philo
FLAGS		:= -Werror -Wall -Wextra
CC			:= gcc

LST_SRCS		:= ft_atoi.c ft_printf.c ft_putchar_fd.c\
				ft_putnbr_fd.c ft_putstr_fd.c main.c \
				printf_function.c

LST_OBJS		:= $(LST_SRCS:.c=.o)
OBJS			= $(addprefix .objects/,$(LST_OBJS))
SRCS			= $(addprefix sources/,$(LST_SRCS))

INCLUDES		= includes/philosophers.h
DIR_INCLUDES	= $(sort $(addprefix -I, $(dir $(INCLUDES))))

NORM		= $(shell norminette sources | grep -c 'Error!')

ifeq ($(NORM), 0)
	NORM_RET = "$(ERASE)$(GREEN)[DONE]$(END) $(NAME)"
else
	NORM_RET = "$(ERASE)$(RED)[NORM]$(END) $(NAME)"
endif

all:		$(NAME)

$(NAME):	$(OBJS) Makefile $(INCLUDES)
	$(CC) $(FLAGS) $(DIR_INCLUDES)

.objects/%.o:		sources/%.c $(INCLUDES) | .objects
		$(CC) $(FLAGS) -c $< -o $@ $(DIR_INCLUDES)
		printf "$(ERASE)$(PINK)[BUILD]$(END) $@"

.objects:
	mkdir -p .objects

clean:
	rm -rf .objects

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean