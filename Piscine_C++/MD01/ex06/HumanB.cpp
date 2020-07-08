/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:36:35 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 20:18:22 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const char *name, Weapon*  arm = NULL)
{
    this->name = strdup(name);
    this->arm = arm;
}

void        attack(void)
{
    std::cout << this->name;
    std::cout << "attacks with his ";
    std::cout << this->arm->type <<"\n";
    return ;
}

void        setWeapon(Weapon* arm)
{
    if (this->arm != NULL)
        delete arm;
    this->arm = arm;
    return ;
}