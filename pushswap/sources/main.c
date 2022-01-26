/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/26 16:12:06 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc < 1)
	{
		exit(EXIT_SUCCESS);
		return (1);
	}
	if (ft_complete_args(argv, &stacka) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
		return (1);
	}
	if (lst_is_sort(stacka) == 1)
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

int	ft_complete_args(char const *argv[], t_list **lst)
{
	int	i;
	int	j;
	int	temp;

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
		lst_add_back(lst, temp);
	}
	return (1);
}
