
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char *)s1);
	str = (void *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, ft_strlen(s1) + ft_strlen(s2) + 1);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
