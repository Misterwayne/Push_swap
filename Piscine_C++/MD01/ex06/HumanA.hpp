/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:36:51 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 20:14:02 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef _HUMANA_H_
#   define _HUMANA_H_

#include <iostream>
#include "Weapon.hpp"

class HumanA{
    public:
        
        char*   name;
        Weapon  arm;
        void    attack(void);
        void    setWeapon(Weapon* arm);
        HumanA(char* name, Weapon arm);
};

#   endif