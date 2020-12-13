
#include "libft.h"

int			line_lenght(char **line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void		free_double_pointer(char ***split)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = *split;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
