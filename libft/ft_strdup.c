
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (*(src + i) != '\0')
		i++;
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}
