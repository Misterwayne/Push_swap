/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:49:31 by mwane             #+#    #+#             */
/*   Updated: 2019/10/22 14:47:12 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newlst;

	if (!(newlst = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}
