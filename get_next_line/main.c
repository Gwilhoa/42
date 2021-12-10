#include "get_next_line.h"
int main(int argc, char const *argv[])
{
	int fd = open("bible.txt", O_RDONLY);
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	return 0;
}
