#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, int size)
{
	unsigned char *tempsrc;
	int i;

	i = 0;
	if (!(tempsrc = malloc(sizeof(src) * size)))
		return NULL;
	while (i <= size)
	{
		*tempsrc = (unsigned char)src;
		tempsrc++;
		src++; 
	}
	i = 0;
	while (tempsrc)
	{
		dest = tempsrc;
		dest++;
		tempsrc--;
	}
	return dest;
}