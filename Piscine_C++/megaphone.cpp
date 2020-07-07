/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:50:52 by truepath          #+#    #+#             */
/*   Updated: 2020/07/02 20:50:53 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int     main(int ac, char **av)
{
    std::locale loc;
    std::string s;
    int         i;

    i = 1;
    if (ac < 2)
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (ac > i)
            s.append(av[i++]);
    }
    i = 0;
    while (s[i])
        std::cout<< std::toupper(s[i++],loc);
    return 0;
}


