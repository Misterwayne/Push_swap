/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:18:44 by mwane             #+#    #+#             */
/*   Updated: 2019/10/22 11:04:29 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*templst;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		del((*lst)->content);
		templst = (*lst);
		free((*lst));
		(*lst) = templst->next;
	}
}
