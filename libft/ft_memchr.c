/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:57:03 by mwane             #+#    #+#             */
/*   Updated: 2019/10/08 14:28:38 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, int size)
{
	while (size >= 0)
	{
		if ((unsigned char)s == c)
		{
			return (void*)s;
		}
		s++;
	}
	return (NULL);
}
