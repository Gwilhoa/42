/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:16:48 by gchatain          #+#    #+#             */
/*   Updated: 2022/04/10 20:13:50 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void ft_strupper(std::string str)
{
	int i = 0;
	while (str[i] != 0)
	{
		str[i] = toupper(str[i]);
		i++;
	}
	std::cout << str;
}

int main(int argc, char const *argv[])
{
	int i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		while (i < argc)
		{
			ft_strupper(argv[i]);
			std::cout << " ";
			i++;
		}
	}
	std::cout << std::endl;
	return 0;
}