/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:46 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/17 11:10:21 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/**
 * @brief baisse tout les éléments le dernier se retrouve en haut
 */
void	reverse_rotate(t_list **lst);

/**
 * @brief monte tout les éléments le premier se retrouve en bas
 */
void	rotate(t_list **lst);

/**
 * @brief met le premier élément d'une liste dans une autre liste
 */
void	push(t_list **from, t_list **to);

/**
 * @brief interverti les 2 premier élément d'une liste
 */
void	swap(t_list **lst);
/////////////////
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
 * @brief supprime le premier élément de la liste
 */
int		lst_clear_top(t_list **lst);

/**
 * @brief supprime le dernier élément de la liste
 */
int		lst_clear_bottom(t_list **lst);

/**
 * @brief ajoute un élément devant la liste
 */
void	lst_add_front(t_list **lst, int nb);

/**
 * @brief ajoute un élément derriere la liste
 */
void	lst_add_back(t_list **lst, int nb);

/**
 * @brief affiche le contenu d'une liste
 */
void	lst_display(t_list *stack);
/////////////////
int		ft_complete_args(char const *argv[], t_list **lst);

#endif
