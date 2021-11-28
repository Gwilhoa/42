/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:18:05 by gchatain          #+#    #+#             */
/*   Updated: 2021/11/27 18:12:33 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putnbr2_fd(unsigned int nb, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char const *str);
int		sizedigit(long long n);
int		ft_printf( const char *format, ...);
char	*ft_changebase(unsigned int nbr, char *base);
int		ft_func_p(unsigned long c);
int		ft_func_x(long long c);
int		ft_func_x2(int c);
int		ft_func_f(double value);
int		ft_func_c(int c);
int		ft_func_i(int c);
int		ft_func_s(char *str);
int		ft_func_u(unsigned int c);
void	print_nb(int nb, int fd);

#endif
