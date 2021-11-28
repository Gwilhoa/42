/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:36:22 by gchatain          #+#    #+#             */
/*   Updated: 2021/07/10 12:25:45 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			f = 1;
		}
		i++;
	}
	if (f == 1)
	{
		ft_sort_int_tab(tab, size);
	}
}
