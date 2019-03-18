#include "header.h"

int main(int argc, char **argv)
{
	DIR *dir;
	char *dir_name;
	struct dirent *entry;


	if (argc == 1)
	{
		dir_name = ft_memalloc(2);
		*dir_name = '.';
		conclusion_without_flags(dir_name);
	}
	// else
	// {

	// }
	// conclusion(dir_name);
}