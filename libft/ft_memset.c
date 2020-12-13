
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *)s;
	while (i < n)
	{
		d[i] = (char)c;
		i++;
	}
	s = (void *)d;
	return (s);
}
