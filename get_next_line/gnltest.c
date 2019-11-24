#include<stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int main(void)
{
    char *commande;
    int i;

    i = 1;
    commande = malloc(sizeof(char) * ft_strlen("gcc -fsanitize=address get_next_line.c -D BUFFER_SIZE=8 && ./a.out") + 1);
    commande[ft_strlen("gcc -fsanitize=address get_next_line.c -D BUFFER_SIZE=8 && ./a.out")] = '\0';
    commande = ft_strncpy(commande,"gcc -fsanitize=address get_next_line.c -D BUFFER_SIZE=8 && ./a.out");
    while (i < 50)
    {
        sprintf(commande, "gcc -fsanitize=address get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=%d && ./a.out",i);
        system(commande);
		i+=1;
    }
}