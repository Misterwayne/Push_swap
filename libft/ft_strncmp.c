/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:19:30 by mwane             #+#    #+#             */
/*   Updated: 2019/10/09 16:38:01 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

int		ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
			i++;
		else
		{
			j += (unsigned char)str1[i] - (unsigned char)str2[i];
			if (j > 0)
				return (1);
			else if (j < 0)
				return (-1);
			else
				return (0);
		}
	}
	return (j);
}

int main(void)
{
	printf("my cmp %d\n",ft_strncmp("\x12\xff\x65\x12\xbd\xde\xad", "\x12\x02", 6));
	printf("thier cmp %d\n",strncmp("\x12\xff\x65\x12\xbd\xde\xad", "\x12\x02", 6));
	printf("%d\n",'\xff' - '\x02');
}