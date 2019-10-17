/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:20:33 by mwane             #+#    #+#             */
/*   Updated: 2019/10/17 14:56:58 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>

int		count_word(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c && str[i])
				i++;
			if (str[i])
				count++;
			else
				i--;
		}
		i++;
	}
	if (count == 0 && str[i - 1] == c)
		return (count);
	if (str[i] != c)
		count++;
	return (count);
}

int		count_letter(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

int		fill_tab(char const *s, char *res, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s == c && *s)
	{
		j++;
		s++;
	}
	while (*s != c && *s)
	{
		res[i++] = *(s++);
		j++;
	}
	res[i] = '\0';
	while (*s == c && *s)
	{
		j++;
		s++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		tablen;
	int		i;

	if (!*s)
	{
		if (!(res = malloc(sizeof(char *) * 1)))
			return (0);
		*res = NULL;
		return (res);
	}
	tablen = (count_word(s, c) + 1);
	i = 0;
	if (!(res = malloc(sizeof(char *) * (tablen))))
		return (0);
	while (i < tablen && *s && tablen != 1)
	{
		if (!(res[i] = malloc(sizeof(char) * ((count_letter(s, c) + 1)))))
			return (NULL);
		s += fill_tab(s, res[i], c);
		i++;
	}
	res[tablen - 1] = NULL;
	return (res);
}
