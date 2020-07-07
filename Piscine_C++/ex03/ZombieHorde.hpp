/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:58:43 by truepath          #+#    #+#             */
/*   Updated: 2020/07/07 15:09:09 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef _ZOMBIEHORDE_H_
# define _ZOMBIEHORDE_H_

#include <iostream>
#include <string>
#include <list>
#include "Zombie.hpp"

class ZombieHorde{
    public:
        int         number;
        Zombie*     zombieGang;
        ZombieHorde(int number);
        void        annononce();    
};

#endif