#include "header.h"

int main(int argc, char **argv)
{
	DIR *dir;
	char *dir_name;
	struct dirent *entry;


	if (argc == 1)
	{
		conclusion_without_flags(".");
		exit(1);
	}
	// else
	// {

	// }
	// conclusion(dir_name);
}