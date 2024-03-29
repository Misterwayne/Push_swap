/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:45:06 by mwane             #+#    #+#             */
/*   Updated: 2021/04/12 15:34:53 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*nstr;
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	if (!(nstr = malloc((sizeof(char) * (i + 1)))))
		return (NULL);
	i = -1;
	while (str[++i])
		nstr[i] = str[i];
	nstr[i] = '\0';
	free((char *)str);
	return (nstr);
}
