#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *str;
	int fd1 = open("file1", O_RDONLY);
	int fd2 = open("file2", O_RDONLY);
	int fd3 = open("file3", O_RDONLY);

	str = get_next_line(fd1);
	printf("%s", str);
	free (str);
	
	str = get_next_line(fd2);
	printf("%s", str);
	str = get_next_line(fd3);
	printf("%s", str);
	str = get_next_line(fd1);
	printf("%s", str);
	
	str = get_next_line(fd2);
	printf("%s", str);

	str = get_next_line(fd3);
	printf("%s", str);

	str = get_next_line(fd1);
	printf("%s", str);
	
	str = get_next_line(fd2);
	printf("%s", str);

	str = get_next_line(fd3);
	printf("%s", str);

	return (0);
}