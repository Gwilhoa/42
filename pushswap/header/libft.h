/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:57:12 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/10 11:10:48 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_lstsize(t_list *lst);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_strlen(char const *str);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *str, int fd);
int				ft_putnbr_fd(int nb, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putendl_fd(char *str, int fd);
void			ft_lstadd_front(t_list **alst, t_list *n);
void			ft_lstadd_back(t_list **alst, t_list *n);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
char			**ft_split(const char *str, char charset);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char const *src);
char			*ft_strjoin(char const *dest, char const *src);
char			*ft_itoa(int n);
char			*ft_strnstr(const char	*big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int				putnbr(int nb);
int				ft_putunsigned(unsigned int nb, int fd);
int				ft_putchangebase(unsigned int nbr, const char *base, int fd);
int				ft_putpointer(unsigned long long nbr, int fd);
int				function_parser(va_list args, int c);
int				ft_printf(const char *str, ...);
#endif
