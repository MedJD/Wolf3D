
#include "libft.h"

int				ft_isdigit(char *line)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if ((line[i] < '0' || line[i] > '9') && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
