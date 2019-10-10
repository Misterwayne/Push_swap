/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:52:04 by mwane             #+#    #+#             */
/*   Updated: 2019/10/10 19:43:37 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ldest;
	unsigned int	b;

	i = 0;
	j = 0;
	ldest = 0;
	b = 0;
	while (dest[ldest] != '\0')
		ldest++;
	while (src[b] != '\0')
		b++;
	i = ldest;
	if (size == 0 || ldest > size)
		return (b + size);
	while (src[j] != '\0' && i + 1 < size)
		dest[i++] = src[j++];
	if (size > 0)
		dest[i] = '\0';
	return (ldest + b);
}
