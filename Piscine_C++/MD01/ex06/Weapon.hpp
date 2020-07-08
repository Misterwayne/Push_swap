/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:24:16 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 20:16:39 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef _WEAPON_H_
#   define _WEAPON_H_
#include <iostream>
#include <string>

class Weapon{
    public:
        char*   type;
        char*   getType(void);
        void    setType(char* type);
        Weapon(char* arm);
};


#   endif
