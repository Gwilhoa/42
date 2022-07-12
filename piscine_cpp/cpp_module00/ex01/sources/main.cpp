#include "phonebook.hpp"

int main(int argc, char const *argv[])
{
	(void) argv;
	phonebook pb;
	std::string str;

	while (1)
	{
		std::cout << "\nEnter command: ";
		std::cin >> str;
		if (str.compare("add") == 0)
			pb.add();
		else if (str.compare("search") == 0)
			pb.search();
		else if (str.compare("exit") == 0)
		{
			pb.~phonebook();
			return (0);
		}
	}
	return argc;
}
