#include "get_next_line.h"

int main(void)
{
	setbuf(stdout, NULL);
	int fd = open("test.txt",'r');
	char *str;
	int	limit;

	str = get_next_line(fd);
	limit = 10;
	while (str)
	{
		printf("'%s'\n",str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}
