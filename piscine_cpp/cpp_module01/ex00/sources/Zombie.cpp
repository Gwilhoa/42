/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:54:28 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/12 13:58:12 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie "<< this->name << " created" <<std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie "<< this->name << " destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}