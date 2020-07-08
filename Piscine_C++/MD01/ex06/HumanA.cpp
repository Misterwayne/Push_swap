/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:36:35 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 20:26:47 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(char *name, Weapon  arm = NULL)
{
    HumanA::name = strdup(name);
    HumanA::arm = arm;
}

void        attack(void)
{
    std::cout << HumanA::name;
    std::cout << "attacks with his ";
    std::cout << HumanA::arm->type <<"\n";
    return ;
}

void        setWeapon(Weapon* arm)
{
    if (HumanA::arm != NULL)
        delete arm;
    HumanA::arm = arm;
    return ;
}