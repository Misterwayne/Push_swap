/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:19:09 by truepath          #+#    #+#             */
/*   Updated: 2020/07/07 15:21:06 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef _ZOMBIE_H_
# define _ZOMBIE_H_

#include <iostream>
#include <string>
#include <stdio.h>

class Zombie{
    public:
        std::string name;
        std::string type;
        std::string roar;
        Zombie(void);
        void advert();
};

#endif