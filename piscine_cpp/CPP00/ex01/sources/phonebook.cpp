/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:57:15 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/12 10:02:02 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
phonebook::phonebook()
{
	std::cout << "Constructor called" << std::endl;
}

phonebook::~phonebook()
{
	std::cout << "destructor called" << std::endl;
}

contact	*phonebook::getcontacts()
{
	return (this->contacts);
}

void	phonebook::add()
{
	int	i;
	i = 0;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	
	std::cout << "Enter first name: ";
	std::cin >> first_name;
	std::cout << "Enter last name: ";
	std::cin >> last_name;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	std::cout << "Enter phone number: ";
	std::cin >> phone_number;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkest_secret;
	
	

	i = 0;
	while (i < 8)
	{
		if (this->contacts[i].getlast() == -1)
		{
			this->contacts[i] = contact(first_name, last_name, nickname, phone_number, darkest_secret);
			this->contacts[i].setlast(0);
			if (i == 7)
				this->contacts[0].setlast(1);
			return;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (this->contacts[i].getlast() == 1)
		{
			this->contacts[i] = contact(first_name, last_name, nickname, phone_number, darkest_secret);
			this->contacts[i + 1].setlast(1);
			if (i == 7)
				this->contacts[0].setlast(1);
			return;
		}
		i++;
	}	
}

std::string formatted_rep(std::string str)
{
	if (str.size() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
	else
	{
		while (str.size() < 10)
		{
			str += " ";
		}
	}
	return (str);
}

void	phonebook::search()
{
	std::string ret;
	std::string temp;
	int	i;

	i = 0;
	ret = "   index  |first name|last name |nickname  |\n";
	while (i < 8)
	{
		if (this->contacts[i].getlast() == -1)
			break;
		ret += "     ";
		ret += std::to_string(i);
		ret += "    |";
		ret += formatted_rep(this->contacts[i].getname());
		ret += "|";
		ret += formatted_rep(this->contacts[i].getlastname());
		ret += "|";
		ret += formatted_rep(this->contacts[i].getnickname());
		ret += "|\n";
		i++;
	}
	if (i == 0)
		ret = "no contact in the phonebook";
	std::cout << ret;
	if (i != 0)
	{
		std::cout << "index : ";
		std::cin >> temp;
		try
		{
			i = std::stoi(temp);
			std::cout << this->contacts[i].tostring();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}