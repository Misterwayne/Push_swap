/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:34:24 by mwane             #+#    #+#             */
/*   Updated: 2019/10/14 13:39:28 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
	len_str = ft_strlen((char *)s1);
	while (is_in_set(s1[i++], set))
		len_str--;
	i = ft_strlen((char *)s1) - 1;
	while (is_in_set(s1[i--], set))
		len_str--;
	if (!(newstr = malloc(sizeof(char) * len_str)))
		return (NULL);
	newstr[len_str] = '\0';
	len_str--;
	i = ft_strlen((char *)s1) - 1;
	while (is_in_set(s1[i], set))
		i--;
	while (s1[i])
	{
		newstr[len_str] = s1[i];
		i--;
		len_str--;
	}
	return (newstr);
}
