/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:36:51 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 20:20:50 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef _HUMANB_H_
#   define _HUMANB_H_

#include <iostream>
#include "Weapon.hpp"

class HumanB{
    public:
        
        char*   name;
        Weapon  arm;
        void    attack(void);
        void    setWeapon(Weapon* arm);
        HumanB(char* name, Weapon arm);
};

#   endif