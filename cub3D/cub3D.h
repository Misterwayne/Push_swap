/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:37:33 by mwane             #+#    #+#             */
/*   Updated: 2019/12/03 17:44:51 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# include <fcntl.h>

typedef struct s_param
{
    int x;
    int y;
    int NO;
    int SO;
    int WE;
    int EA;
    int S;
    int F;
    int C;
}              t_param;

void	fill_params(char* str, t_param *params);
static int		get_str_len(long nbr);
char			*ft_itoa(int n);

#endif