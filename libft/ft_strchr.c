
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*pt;

	i = 0;
	pt = (char *)s;
	while (pt[i])
	{
		if (pt[i] == (char)c)
			return (&pt[i]);
		i++;
	}
	if (pt[i] == (char)c)
		return (&pt[i]);
	return (NULL);
}
