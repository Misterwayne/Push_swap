/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:55:52 by mwane             #+#    #+#             */
/*   Updated: 2019/10/08 17:25:29 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	unsigned char *psrc;
	unsigned char *pdest;

	pdest = (unsigned char*)dest;
	psrc = (unsigned char*)src;
	while (size-- > 0)
	{
		if (*psrc == (unsigned char)c)
			return (dest);
		*(pdest++) = *(psrc++);
	}
	return (NULL);
}



