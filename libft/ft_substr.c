/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:50:03 by startne           #+#    #+#             */
/*   Updated: 2019/10/10 16:38:03 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*newstr;

	if (!(newstr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	start += - 1;
	while (s[++start] && start < len)
	{
		newstr[start] = s[start];
	}
	newstr[start] = '\0';
	return (newstr);
}

