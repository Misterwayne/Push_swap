/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:24:00 by truepath          #+#    #+#             */
/*   Updated: 2020/07/06 17:28:28 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int     main(void)
{
    Zombie *zom;
    ZombieEvent flood;

    flood.setZombietype = "Nice Zombie";
    zom = flood.newZombie("George");
    zom->advert();
    
    zom = flood.randomChump();
    delete zom;

    zom = flood.randomChump();
    delete zom;

    zom = flood.randomChump();
    delete zom;

    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    zom = flood.randomChump();
    delete zom;
    return 0;
}