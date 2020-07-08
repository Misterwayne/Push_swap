/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:23:51 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 20:15:54 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

char    *Weapon::getType(void)
{
	return Weapon::type;
}

void    Weapon::setType(char * type)
{
	delete this.type;
	this.type = strdup(type);
	return ;
}