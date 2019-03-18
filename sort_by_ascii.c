#include "header.h"

char	**put_to_matrix(char *dir_name, char **matrix)
{
	DIR				*dir;
	struct dirent	*entry;
	int 			i;

	i = 0;
	dir = opendir(dir_name);
	if (!dir) // можно убрать
	{
		perror("diropen");
		exit(1);
	}
	matrix = (char**)malloc(sizeof(char *) * number_of_files(dir_name));
	while ((entry = readdir(dir)) != NULL)
	{
		matrix[i] = ft_strdup(entry->d_name);
		// printf("%s\n", matrix[i]);
		i++;
	}
	return (matrix);
}

void	sort_by_ascii(char *dir_name) // освобождение памяти
{
	char	**matrix;
	int		i;
	int		num;
	int		swap_counter;

	swap_counter = 0;
	i = 0;
	num = number_of_files(dir_name); // вызываем функцию подсчета (1)
	matrix = put_to_matrix(dir_name, matrix); // и тут (1)

	printf("matrix before sort\n");
	while(i != 10)
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	i = 0;
	
	while (swap_counter != num)
	{
		if (matrix[i + 1] == NULL)
			i = 0;
		if (ft_strcmp(matrix[i], matrix[i + 1]) >= 0)
		{
			matrix = ft_strswap(matrix, i, i + 1);
			i++;
		}
		else
			swap_counter++;
	}

	i = 0;
	printf("\n\nmatrix after sort\n");
	while(i != 10)
	{
		printf("%s\n", matrix[i]);
		i++;
	}

}