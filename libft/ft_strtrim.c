/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:34:24 by mwane             #+#    #+#             */
/*   Updated: 2019/10/16 16:59:33 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		lstrlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_in_set(char c, char const *set)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		len_str;

	i = 0;
	len_str = lstrlen((char *)s1);
	while (is_in_set(s1[i++], set) && s1[i])
		len_str--;
	i = lstrlen((char *)s1) - 1;
	while (is_in_set(s1[i--], set) && i >= 0)
		len_str--;
	if (!(newstr = malloc(sizeof(char) * len_str + 1)))
		return (NULL);
	newstr[len_str + 1] = '\0';
	len_str--;
	i = lstrlen((char *)s1) - 1;
	while (is_in_set(s1[i], set) && i >= 0)
		i--;
	while (s1[i] && len_str >= 0 && i >= 0)
	{
		newstr[len_str] = s1[i];
		i--;
		len_str--;
	}
	return (newstr);
}
