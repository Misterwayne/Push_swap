int		ft_strncmp(char *str1, char *str2, unsigned int n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
			i++;
		else
		{
			j += str1[i] - str2[i];
			return (j);
		}
	}
	return (j);
}
