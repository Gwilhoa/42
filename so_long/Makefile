# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 12:12:30 by gchatain          #+#    #+#              #
#    Updated: 2022/01/26 15:15:13 by gchatain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m

LST_SRCS        = test.c
LST_OBJS        =   ${LST_SRCS:.c=.o}
SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))
INCLUDES    = includes/fdf.h libmlx.dylib
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
LIBX        = -lmlx -framework OpenGL -framework AppKit
NAME        =   fdf
RM          =   rm -f
all:        ${NAME}
.objects/%.o:       sources/%.c ${INCLUDES}
            mkdir -p .objects
            @${CC} ${CFLAGS}  -I includes libmlx/libmlx.dylib -c $< -o $@
            @echo "${BLUE}[BUILD]${END} $@"
${NAME}:    ${OBJS} ${INCLUDES} Makefile
            make -C ./libft
            make -C ./libmlx
            gcc ${OBJS} libft/*.o -I includes libmlx/libmlx.dylib -o $@
            @echo "${GREEN}[CREATE]${END} ${NAME}"
clean:
            @${RM} ${OBJS}
            make clean -C ./libft
            make clean -C ./libmlx
            @echo "${RED}[DELETE]${END} *.o"
fclean:     clean
            @${RM} -r ${NAME} fdf .objects
            @echo "${RED}[DELETE]${END} ${NAME}"
re:         fclean all
.PHONY:     all clean fclean re
