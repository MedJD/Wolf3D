
#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;
	int n;
	int k;

	j = 0;
	i = ft_strlen(dest);
	n = ft_strlen((char *)src);
	k = i + n;
	*(dest + i) = *src;
	while (i < k)
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + k) = '\0';
	return (dest);
}
