/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/27 13:06:35 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_list	*stacka;
	t_list	*stackb;
	t_list	*temp;

	temp = NULL;
	stacka = NULL;
	stackb = NULL;
	if (argc < 1)
	{
		exit(EXIT_SUCCESS);
		return (1);
	}
	if (ft_complete_args(argv, &stacka, &temp) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
		return (1);
	}
	if (ft_lstsize(stacka) <= 1 || lst_is_sort(stacka) == 1)
	{
		exit(EXIT_SUCCESS);
		return (1);
	}
	tri(&stacka, &stackb);
	exit(EXIT_SUCCESS);
	return (argc);
}

int	lst_is_in(t_list *lst, int nb)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst);
	while (i < size)
	{
		if (lst_get_index(lst, i) == nb)
			return (1);
		i++;
	}
	return (0);
}

void	lst_replace_index(t_list **lst, int index)
{
	int		i;
	t_list	*temp;
	t_list	*base;

	base = *lst;
	temp = base;
	i = 0;
	if (index > ft_lstsize(temp))
		return ;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	*(int *) temp->content = INT_MAX;
	*lst = base;
	return ;
}

void	ft_initstack(t_list **temp, t_list **lst)
{
	int	*nbr;
	int	i;

	i = 0;
	nbr = ft_calloc(ft_lstsize(*temp), sizeof(int));
	while (ft_lstsize(*temp) > i)
	{
		nbr[lst_lowest_index(*temp)] = i;
		lst_replace_index(temp, lst_lowest_index(*temp));
		i++;
	}
	i = 0;
	while (ft_lstsize(*temp) > i)
	{
		ft_putnbr_fd(nbr[i], 1);
		i++;
	}
	i = 0;
	while (ft_lstsize(*temp) > i)
		lst_add_back(lst, nbr[i++]);
	lst_display(*lst);
	return ;
}

int	ft_complete_args(char const *argv[], t_list **lst, t_list **temp1)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j++;
		}
		temp = ft_atoi(argv[i]);
		if (ft_strncmp(ft_itoa(temp), argv[i], ft_strlen(argv[i]))
			&& ft_strncmp(argv[i], "-0", 2))
			return (0);
		j = 0;
		if (lst_is_in(*lst, temp) == 1)
			return (0);
		lst_add_back(temp1, temp);
	}
	ft_initstack(temp1, lst);
	return (1);
}
