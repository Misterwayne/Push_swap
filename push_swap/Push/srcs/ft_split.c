/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:20:33 by mwane             #+#    #+#             */
/*   Updated: 2021/10/18 20:15:40 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/checker.h"

static	int	count_word(char const *str, char c)
{
	int	i;
	int	count;

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

static int	count_letter(char const *s, char c)
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

static int	fill_tab(char const *s, char *res, char c)
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
	int		i;

	if (s == NULL || !*s)
	{
		res = malloc(sizeof(char *) * 1);
		if (!(res))
			return (NULL);
		*res = NULL;
		return (res);
	}
	i = -1;
	res = malloc(sizeof(char *) * ((count_word(s, c) + 1)));
	if (!(res))
		return (0);
	while (++i < (count_word(s, c) + 1) && *s && (count_word(s, c) + 1) != 1)
	{
		res[i] = malloc(sizeof(char) * ((count_letter(s, c) + 1)));
		if (!(res[i]))
			return (free_tab(res, i));
		s += fill_tab(s, res[i], c);
	}
	res[i - 1] = NULL;
	return (res);
}
