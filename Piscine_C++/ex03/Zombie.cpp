/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:00:25 by truepath          #+#    #+#             */
/*   Updated: 2020/07/07 15:23:09 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


void Zombie::advert()
{
    char message[100];
            
    std::sprintf(message,"<%s (%s)> %s\n",Zombie::name.c_str(),Zombie::type.c_str(),Zombie::roar.c_str());
    std::cout << message;
    return ;
}

Zombie::Zombie(void)
{
    char **name_list = new char*[6];
    std::string     base_type;
    std::string     base_roar;

    base_roar = "Braiiiinn ....";
    base_type = "stupid zombie";
    name_list[0] = strdup("Mitch");
    name_list[1] = strdup("Zombie_juice");
    name_list[2] = strdup("the architeck");
    name_list[3] = strdup("Brook");
    name_list[4] = strdup("Zombie Man");
    name_list[5] = strdup("Basic Zombie");
    Zombie::name = name_list[std::rand() % (5 - 0 + 1) + 0];
    Zombie::roar = base_roar;
    Zombie::type = base_type;
    if (Zombie::name.compare("Mitch") == 0)
    {
        Zombie::type = "Flatbush",   
        Zombie::roar = "Let me see you talk when your dead!!!";
    }
    else if (name.compare("Brook") == 0)
    {
        Zombie::type = "Mugiwara";
        Zombie::roar = "Yohohohohohohoho";
    }
    else if  (name.compare("Zombie_juice") == 0)
    {
        Zombie::roar = "Zombie Gannng ...";
        Zombie::type = "Flatbush";
    }
    else if  (name.compare("the architeck") == 0)
    {
        Zombie::roar = "I got a woll world on my end now...";
        Zombie::type = "Flatbush";
    }
    return ;
}
