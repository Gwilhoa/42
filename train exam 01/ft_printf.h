#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	putnbr(int nb);
int ft_putunsigned(unsigned int nb);
int	ft_putnbr(int nbr);
int ft_puthexnbr(unsigned int nbr);
int ft_putpointer(unsigned long long nbr);
int ft_puthexnbr2(unsigned int nbr);
int	ft_printf(const char *str, ...);

#endif
