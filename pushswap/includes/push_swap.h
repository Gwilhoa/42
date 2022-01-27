/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:46 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/27 11:51:34 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

/**
 * @brief baisse tout les éléments le dernier se retrouve en haut
 */
void	reverse_rotate(t_list **lst, char c);

/**
 * @brief monte tout les éléments le premier se retrouve en bas
 */
void	rotate(t_list **lst, char c);

/**
 * @brief met le premier élément d'une liste dans une autre liste
 */
void	push(t_list **from, t_list **to, char c);

/**
 * @brief interverti les 2 premier élément d'une liste
 */
void	swap(t_list **lst, char c);

/**
 * @brief récupère l'élement a la position donée d'une liste
 */
int		lst_get_index(t_list *lst, int index);

/**
 * @brief récupère le premier élément d'une liste
 */
int		lst_get_top(t_list *lst);

/**
 * @brief récupère le dernier élément d'une liste
 */
int		lst_get_bottom(t_list *lst);

/**
 * @brief ajoute un élément derriere la liste
 */
void	lst_add_back(t_list **lst, int nb);

/**
 * @brief affiche le contenu d'une liste
 */
void	lst_display(t_list *stack);

/**
 * @brief vois si un nombre est dans une liste
 */
int		lst_is_in(t_list *lst, int nb);

/**
 * @brief vois si une liste est triée
 */
int		lst_is_sort(t_list *lst);

/**
 * @brief retrouve le plus petit nombre de la lst
 */
int		lst_lowest(t_list *lst);

int		lst_highest(t_list *lst);

int		lst_lowest_index(t_list *lst);

int		search_place(t_list *lst, int index);

t_list	*get_top_link(t_list **lst);

t_list	*get_bottom_link(t_list **lst);

void	lst_scroll(t_list **lst);

/////
int		ft_complete_args(char const *argv[], t_list **lst, t_list **temp1);
int		tri(t_list **stacka, t_list **stackb);
int		tri_three(t_list **stacka);
int		tri_main(t_list **stacka, t_list **stackb, int size);
int		tri_bubble(t_list **stacka, t_list **stackb);

#endif
