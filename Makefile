# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 13:27:33 by gchatain          #+#    #+#              #
#    Updated: 2022/04/11 14:12:49 by gchatain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

42:
	$(shell git clone https://github.com/gwilhoa/libft)
	$(shell git clone https://github.com/gwilhoa/piscine_cpp)
	$(shell git clone https://github.com/gwilhoa/push_swap)
	$(shell git clone https://github.com/gwilhoa/so_long)
	$(shell git clone https://github.com/gwilhoa/philosophers)
	$(shell git clone https://github.com/gwilhoa/minitalk)
	$(shell git clone https://github.com/gwilhoa/ft_printf)
	$(shell git clone https://github.com/gwilhoa/piscine)
	$(shell git clone https://github.com/gwilhoa/get_next_line)
	$(shell git clone https://github.com/gwilhoa/minshell)
clean:
	rm -rf libft
	rm -rf piscine_cpp
	rm -rf minitalk
	rm -rf minshell
	rm -rf piscine
	rm -rf push_swap
	rm -rf so_long
	rm -rf philosophers
	rm -rf ft_printf
	rm -rf get_next_line

.PHONY: 42 clean