/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:32:55 by truepath          #+#    #+#             */
/*   Updated: 2020/07/07 15:47:04 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <unistd.h>

int     main(int ac, char** av)
{
    std::string     message;
    int             i;

    i = 0;
    if (ac > 1)
        message = av[1];
    else
        message = "HI THIS IS BRAIN\n";
    
    std::cout << message;
    while (message[i])
    {
        putchar(message.c_str()[i]);
        i++;
    }
    return 0;
}