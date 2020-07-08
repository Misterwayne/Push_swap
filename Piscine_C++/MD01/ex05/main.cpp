/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:41:53 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 19:16:59 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Human.hpp"

int main()
{
    Human bob;

    std::cout << bob.identify() << std::endl;
    std::cout << bob.veaucer.identify();
    return 0;
}