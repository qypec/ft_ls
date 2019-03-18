#include "header.h"



void	conclusion(char *dir_name)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(dir_name);
	if (!dir)
	{
		perror("diropen");
		exit(1);
	}
}