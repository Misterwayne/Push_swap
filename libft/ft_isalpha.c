#include <stdlib.h>

int		ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c <= 122 && c >= 97))
		return 1;
	else
		return 0;
}