
#include "libft.h"

char	**ft_strswap(char **matrix, int first, int second)
{
	char	*tmp;

	tmp = ft_strdup(matrix[first]);
	ft_strdel(&matrix[first]);
	matrix[first] = ft_strdup(matrix[second]);
	ft_strdel(&matrix[second]);
	matrix[second] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (matrix);
}