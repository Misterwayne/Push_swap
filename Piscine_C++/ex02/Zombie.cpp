/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:00:25 by truepath          #+#    #+#             */
/*   Updated: 2020/07/06 17:39:33 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"


void Zombie::advert()
{
    char message[100];
            
    std::sprintf(message,"<%s (%s)> %s\n",Zombie::name.c_str(),Zombie::type.c_str(),Zombie::roar.c_str());
    std::cout << message;
    return ;
}

