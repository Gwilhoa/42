/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:30:46 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/12 16:55:17 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
# include "Weapon.hpp"
class HumanB
{
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon &weapon);
	void	attack();
	~HumanB();
};
#endif