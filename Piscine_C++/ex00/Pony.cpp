/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:39:55 by truepath          #+#    #+#             */
/*   Updated: 2020/07/04 04:48:16 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

class   Pony {
    public:
        std::string     name;
        std::string     age;
        std::string     heigth;
        std::string     width;
        std::string     color;
        void ponyonTheHeap(void)
        {
            Pony *pony2;
            pony2 = new Pony;
            pony2->name = "Polly";
            std::cout << "the heap poney name is : " << pony2->name <<"\n";
            return ;
        }
};

void ponyonTheHeap(void)
{
    Pony *pony2;
    pony2 = new Pony;
    pony2->name = "Polly";
    std::cout << "the heap poney name is : " << pony2->name <<"\n";
    delete pony2;
    return ;
}

void ponyonTheStack(void)
{
    Pony pony1;
    pony1.name = "Rolly";
    std::cout << "the stack poney name is : " << pony1.name <<"\n";
    return ;
}
