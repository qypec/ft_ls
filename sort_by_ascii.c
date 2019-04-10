#include "ft_ls.h"

char	**put_to_matrix(char *dir_name, int num)
{
	DIR				*dir;
	struct dirent	*entry;
	int 			i;
	char			**matrix;

	i = 0;
	dir = opendir(dir_name);
	if (!dir) // можно убрать
	{
		perror("diropen");
		exit(1);
	}
	matrix = (char**)malloc(sizeof(char *) * (num + 1));
	if (matrix == NULL)
		return (NULL);
	while ((entry = readdir(dir)) != NULL)
	{
		matrix[i] = ft_strdup(entry->d_name);
		i++;
	}
	matrix[i] = NULL;
	closedir(dir);
	return (matrix);
}

char	**sort_by_ascii(char *dir_name)
{
	char	**matrix;
	int		i;
	int		num;
	int		swap_counter;

	swap_counter = 0;
	i = 0;
	num = number_of_files(dir_name);
	matrix = put_to_matrix(dir_name, num);
	while (swap_counter != num - 1)
	{
		if (matrix[i + 1] == NULL)
		{
			i = 0;
			swap_counter = 0;
		}
		if (ft_strcmp(matrix[i], matrix[i + 1]) >= 0)
			matrix = ft_strswap(matrix, i, i + 1);
		else
			swap_counter++;
		i++;
	}
	
	return (matrix);
}

	// printf("matrix before sort\n");
	// while(i != 15)
	// {
	// 	printf("%s\n", matrix[i]);
	// 	i++;
	// }
	// i = 0;

	// printf("\n\n\n");
	// printf("strswap = %d\n", ft_strcmp(matrix[5], matrix[6]));

	// i = 0;
	// printf("\n\nmatrix after sort\n");
	// while(i != 15)
	// {
	// 	printf("%s\n", matrix[i]);
	// 	i++;
	// }