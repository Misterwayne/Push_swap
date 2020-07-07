/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:21:01 by truepath          #+#    #+#             */
/*   Updated: 2020/07/06 17:45:06 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef _ZOMBIEEVENT_H_
# define _ZOMBIEEVENT_H_

#include <iostream>
#include <string>
#include "Zombie.hpp"
#include <stdio.h>


class ZombieEvent{
    public:
        std::string setZombietype;
        Zombie* newZombie(std::string name);
        Zombie* randomChump(void);
};

#endif