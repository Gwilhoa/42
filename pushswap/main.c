/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/22 10:16:38 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (ft_complete_args(argv, &stacka) == 0)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
		return (0);
	}
	if (lst_is_sort(stacka) == 1)
	{
		ft_printf("\n");
		exit(EXIT_SUCCESS);
		return (0);
	}
	tri(&stacka, &stackb);
	exit(EXIT_SUCCESS);
	return (argc);
}

int	lst_is_in(t_list *lst, int nb)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(lst))
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

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j++;
		}
		temp = ft_atoi(argv[i]);
		j = 0;
		if (lst_is_in(*lst, temp) == 1)
			return (0);
		lst_add_back(lst, temp);
		i++;
	}
	return (1);
}
