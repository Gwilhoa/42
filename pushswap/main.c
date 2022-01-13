/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:18:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/01/13 13:49:43 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char const *argv[])
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (ft_complete_args(argv, &stacka) == 0)
		ft_printf("\n");
	return (argc);
}

int	ft_complete_args(char const *argv[], t_list **lst)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
			j++;
		}
		
		temp = ft_atoi(argv[i]);
		i++;
	}
	
}
