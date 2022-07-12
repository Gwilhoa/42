/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:49:58 by gchatain          #+#    #+#             */
/*   Updated: 2022/07/12 15:56:35 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;
	std::string str;
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	str = "HI THIS IS BRAIN";
	std::cout << "adresse de str : " << &str << std::endl;
	std::cout << "adresse de stringPTR : " << stringPTR << std::endl;
	std::cout << "adresse de stringREF : " << &stringREF << std::endl;

	std::cout << "valeur de str : " << str << std::endl;
	std::cout << "valeur de stringPTR : " << *stringPTR << std::endl;
	std::cout << "valeur de stringREF : " << stringREF << std::endl;
	return 0;
}
