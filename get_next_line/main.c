#include "get_next_line.h"

int main(void)
{
	setbuf(stdout, NULL);
	int fd = open("files/alternate_line_nl_no_nl",'r');
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
