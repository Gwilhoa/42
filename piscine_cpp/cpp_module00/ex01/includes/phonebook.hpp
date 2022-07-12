/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:49:13 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/11 16:15:13 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
class phonebook
{
private:
	contact contacts[8];

public:
	phonebook();
	~phonebook();
	
	contact		*getcontacts();
	void		add();
	void		search();
};

