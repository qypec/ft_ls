#include "header.h"

void	conclusion_without_flags(char *dir_name)
{
	DIR				*dir;
	struct dirent	*entry;
	int				num;

	dir = opendir(dir_name);
	if (!dir)
	{
		perror("diropen");
		exit(1);
	}
	// num = number_of_files(dir_name);
	sort_by_ascii(dir_name);
	// printf("num = %d\n", num);
	// while ((entry = readdir(dir)) != NULL)
	// {
	// 	if (entry->d_name[0] != '.')
	// 	{
	// 		// print_in_ascii_order(entry);
	// 		ft_putstr(entry->d_name);
	// 		ft_putstr("   ");
	// 	}
	// }
	closedir(dir);
}