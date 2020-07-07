/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:00:42 by truepath          #+#    #+#             */
/*   Updated: 2020/07/07 15:09:59 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int number)
{
    ZombieHorde::zombieGang = new Zombie[number];
    ZombieHorde::number = number;
    return ;
}

void     ZombieHorde::annononce(void)
{
    for (int i = 0; i < ZombieHorde::number ; i++)
    {
        ZombieHorde::zombieGang[i].advert();
    }
}