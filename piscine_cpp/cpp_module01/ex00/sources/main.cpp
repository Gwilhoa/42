/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:15:26 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/12 14:18:44 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	void	randomChump(std::string str);
	Zombie	*newZombie(std::string name);
	Zombie	*zombie = newZombie("Bob");
	zombie->announce();
	zombie->~Zombie();
	randomChump("Yann");
	delete zombie;
	return 0;
}
