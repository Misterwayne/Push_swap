/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:45:06 by mwane             #+#    #+#             */
/*   Updated: 2019/10/09 18:23:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*nstr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(nstr = malloc((sizeof(char) * i) + 1)))
		return (NULL);
	i = 0;
	while (str[i++])
		nstr[i] = str[i];
	nstr[i] = '\0';
	return (nstr);
}
