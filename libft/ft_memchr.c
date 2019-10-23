/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:57:03 by mwane             #+#    #+#             */
/*   Updated: 2019/10/22 15:40:47 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	unsigned char *ps;

	ps = (unsigned char *)s;
	while (size-- > 0)
	{
		if (*ps == (unsigned char)c)
		{
			return (ps);
		}
		ps++;
	}
	return (NULL);
}
