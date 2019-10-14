/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:20:33 by mwane             #+#    #+#             */
/*   Updated: 2019/10/14 16:59:57 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		count_word(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if ((str[i + 1] != c && str[i] == c))
			count++;
		i++;
	}
	if (str[i - 1] != c)
		count++;
	return (count);
}

int		count_letter(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *(s++))
		i++;
	return (i);
}

int		fill_tab(char const *s, char *res, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s == c && *(s++))
		j++;
	while (*s != c && *s)
	{
		res[i++] = *(s++);
		j++;
	}
	res[i] = '\0';
	while (*s == c && *(s++))
		s++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		tablen;
	int		i;

	tablen = count_word(s, c) + 1;
	i = 0;
	if (!(res = malloc(sizeof(char *) * tablen)))
		return (0);
	res[tablen] = NULL;
	while (i < tablen)
	{
		if (!(res[i] = malloc(sizeof(char) * (count_letter(s, c) + 1))))
			return (NULL);
		s += fill_tab(s, res[i], c);
		i++;
	}
	res[tablen - 1] = NULL;
	return (res);
}