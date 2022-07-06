/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:49:13 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/06 13:23:47 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
class phonebook
{
private:
	contact contacts[8];
	int size;
	int capacity;
public:
	phonebook();
	~phonebook();
};

phonebook::phonebook(/* args */)
{
	
}

phonebook::~phonebook()
{
}
