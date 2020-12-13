
#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int valeur;
	int signe;

	i = 0;
	valeur = 0;
	while ((str[i] == '\n') || (str[i] == ' ') || (str[i] == '\t') ||
			(str[i] == '\f') || (str[i] == '\v') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		signe = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((*(str + i) >= '0') && (*(str + i) <= '9'))
	{
		valeur = (valeur * 10) + ((int)*(str + i) - 48);
		i++;
	}
	if (signe == 1)
		return (-valeur);
	return (valeur);
}
