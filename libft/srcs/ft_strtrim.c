/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:34:24 by mwane             #+#    #+#             */
/*   Updated: 2019/10/13 15:57:19 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int		is_in_set(char c, char *set)
{
	int i;

	i = -1;
	while (set[++i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

char 	*trim_str(char *str, char *set)
{
	char	*nstr;
	int 	i;

	i = -1;
	if (!(nstr = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[++i])
	{
		if (is_in_set(str[i], set))
		{
			nstr[i++] = 1;
			break ;
		}
		nstr[i] = str[i];
	}
	i = ft_strlen(str) + 1;
	while (--i >= 0)
	{
		if (is_in_set(str[i], set))
		{
			nstr[i--] = 1;
			break ;
		}
		nstr[i] = str[i];
	}
	return (nstr);
}

char	*trim_more(char *nstr, const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (nstr[i] == 1)
			i++;
		else
		{
			nstr[i] = str[i];
			i++;
		}
	}
	nstr[i] = '\0';
	return (nstr);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	char *res;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char*)s1);
	res = trim_more(trim_str((char*)s1, (char*)set), (char*)s1);
	return (res);
}
