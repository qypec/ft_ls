#include "header.h"

int		number_of_files(char *dir_name)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	count = 0;
	dir = opendir(dir_name);
	if (!dir) // можно убрать
	{
		perror("diropen");
		exit(1);
	}
	while((entry = readdir(dir)) != NULL)
		count++;
	closedir(dir);
	return (count);
}