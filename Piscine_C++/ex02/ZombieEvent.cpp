/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:22:42 by truepath          #+#    #+#             */
/*   Updated: 2020/07/07 13:53:52 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ZombieEvent.hpp"
#include "Zombie.hpp"


Zombie*     ZombieEvent::newZombie(std::string name)
{
    Zombie*   zombie;
    
    zombie = new Zombie;
    zombie->type =  ZombieEvent::setZombietype;
    zombie->roar = "Braiiinnn .....";
    if (name.compare("Mitch") == 0)
    {
        zombie->type = "Flatbush",   
        zombie->roar = "Let me see you talk when your dead!!!";
    }
    else if (name.compare("Brook") == 0)
    {
        zombie->type = "Mugiwara";
        zombie->roar = "Yohohohohohohoho";
    }
    else if  (name.compare("Zombie_juice") == 0)
    {
        zombie->roar = "Zombie Gannng ...";
        zombie->type = "Flatbush";
    }
    else if  (name.compare("the architeck") == 0)
    {
        zombie->roar = "I got a woll world on my end now...";
        zombie->type = "Flatbush";
    }
    zombie->name = name;
    return zombie;
}


Zombie* ZombieEvent::randomChump(void)
{
    Zombie*     zombie;
    std::string name;
    char **name_list = new char*[6];

    name_list[0] = strdup("Mitch");
    name_list[1] = strdup("Zombie_juice");
    name_list[2] = strdup("the architeck");
    name_list[3] = strdup("Brook");
    name_list[4] = strdup("Zombie Man");
    name_list[5] = strdup("Basic Zombie");
    name = name_list[std::rand() % (5 - 0 + 1) + 0]; 
    zombie = ZombieEvent::newZombie(name);
    zombie->advert();
    return zombie;
};