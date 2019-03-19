#include "header.h"

char	**put_to_matrix(char *dir_name)
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
	matrix = (char**)malloc(sizeof(char *) * (number_of_files(dir_name) + 1));
	if (matrix == NULL)
		return (NULL);
	while ((entry = readdir(dir)) != NULL)
	{
		matrix[i] = ft_strdup(entry->d_name);
		// printf("%s\n", matrix[i]);
		i++;
	}
	matrix[i] = NULL;
	// printf("%s\n", matrix[i]);
	closedir(dir);
	return (matrix);
}

void	sort_by_ascii(char *dir_name) // дописать освобождение памяти
{
	char	**matrix;
	int		i;
	int		num;
	int		swap_counter;

	swap_counter = 0;
	i = 0;
	num = number_of_files(dir_name); // вызываем функцию подсчета (1)
	matrix = put_to_matrix(dir_name); // и тут (1)

	// printf("matrix before sort\n");
	// while(i != 15)
	// {
	// 	printf("%s\n", matrix[i]);
	// 	i++;
	// }
	// i = 0;

	// printf("\n\n\n");
	// printf("strswap = %d\n", ft_strcmp(matrix[5], matrix[6]));
	
	while (swap_counter != num - 1)
	{
		if (matrix[i + 1] == NULL)
		{
			i = 0;
			swap_counter = 0;
		}
		// printf("strswap = %d\n", ft_strcmp(matrix[i], matrix[i + 1]));
		if (ft_strcmp(matrix[i], matrix[i + 1]) >= 0)
		{
			// printf("matrix[i] = %s\nmatrix[i + 1] = %s\n", matrix[i], matrix[i + 1]);
			matrix = ft_strswap(matrix, i, i + 1);
			
			// printf("matrix[i] = %s\nmatrix[i + 1] = %s\n\n\n", matrix[i], matrix[i + 1]);
		}
		else
			swap_counter++;
		i++;
	}

	// matrix = ft_matrixfree(&matrix, num + 1);


	// i = 0;
	// printf("\n\nmatrix after sort\n");
	// while(i != 15)
	// {
	// 	printf("%s\n", matrix[i]);
	// 	i++;
	// }

}