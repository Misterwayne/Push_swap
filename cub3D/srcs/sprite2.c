/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:57:21 by mwane             #+#    #+#             */
/*   Updated: 2020/02/12 16:06:15 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void     get_sprite(t_param *params,int x, int y, int i)
{
	if (i < params->numsprite)
	{
		params->sprite->sprt_list[i] = malloc(sizeof(char) * 3);
		params->sprite->sprt_list[i][0] = x;
		params->sprite->sprt_list[i][1] = y;
		params->sprite->sprt_list[i][2] = '\0';
	}
	return ;
}