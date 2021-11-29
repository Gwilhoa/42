#include "get_next_line.h"

int main(void)
{
	int fd = open("test.txt",'r');
	char *str;

	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n",str);
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	free(str);
}
