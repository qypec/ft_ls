
#include "libft.h"

void	ft_putmatrix(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_putendl(str[i]);
		i++;
	}
}
