/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:45:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/12 14:14:56 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string str)
{
	Zombie *zombie = new Zombie[N];
	while (N--)
	{
		zombie[N].setName(str);
	}
	return zombie;
}