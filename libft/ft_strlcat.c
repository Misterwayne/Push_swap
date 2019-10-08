int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	a;
	unsigned int	b;

	i = 0;
	j = 0;
	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0')
		b++;
	i = a;
	if (size == 0 || a > size)
		return (b + size);
	while (src[j] != '\0' && j < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (a + b);
}