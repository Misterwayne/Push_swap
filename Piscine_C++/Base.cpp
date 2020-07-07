/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 20:50:48 by truepath          #+#    #+#             */
/*   Updated: 2020/07/03 16:48:29 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdio.h>

class Contact {
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string login;
        std::string postal;
        std::string address;
        std::string email;
        std::string phone_number;
        std::string birth_day;
        std::string fav_meal;
        std::string underwear_color;
        std::string darkest_secret;
};


Contact    add_contact(void)
{
    std::string input;
    Contact     entry;

    std::cout << "Creating new contact :\n";
    std::cout << "first name ? : ";
    std::getline(std::cin,input);
    entry.first_name = input;
    std::cout << entry.first_name <<"\n";
    std::cout << "last name ? : ";
    std::getline(std::cin,input);
    entry.last_name = input;
    std::cout << entry.last_name <<"\n";
    std::cout << "nickname ? : ";
    std::getline(std::cin,input);
    entry.nickname = input;
    std::cout << entry.nickname <<"\n";
    std::cout << "login ? : ";
    std::getline(std::cin,input);
    entry.login = input;
    std::cout << entry.login <<"\n";
    std::cout << "postal ? : ";
    std::getline(std::cin,input);
    entry.postal = input;
    std::cout << entry.postal <<"\n";
    std::cout << "address ? : ";
    std::getline(std::cin,input);
    entry.address = input;
    std::cout << entry.address <<"\n";
    std::cout << "email ? : ";
    std::getline(std::cin,input);
    entry.email = input;
    std::cout << entry.email <<"\n";
    std::cout << "phone number ? : ";
    std::getline(std::cin,input);
    entry.phone_number = input;
    std::cout << entry.phone_number <<"\n";
    std::cout << "birth day ? : ";
    std::getline(std::cin,input);
    entry.birth_day = input;
    std::cout << entry.birth_day <<"\n";
    std::cout << "favorite meal ? : ";
    std::getline(std::cin,input);
    entry.fav_meal = input;
    std::cout << entry.fav_meal <<"\n";
    std::cout << "underwear color ? : ";
    std::getline(std::cin,input);
    entry.underwear_color = input;
    std::cout << entry.underwear_color <<"\n";
    std::cout << "darkest secret ? : ";
    std::getline(std::cin,input);
    entry.darkest_secret = input;
    std::cout << entry.darkest_secret <<"\n";
    std::cout << "Done !\n";
    std::cout << "Contact Added !\n\n";
    return entry;
}

void    display(Contact entry)
{
    std::cout << "firstname : " << entry.first_name <<"\n";
    std::cout << "last name : " << entry.last_name <<"\n";
    std::cout << "nickname" << entry.nickname <<"\n";
    std::cout << "login : " << entry.login <<"\n";
    std::cout << "postal : " << entry.postal <<"\n";
    std::cout << "adress" << entry.address <<"\n";
    std::cout << "email" << entry.email <<"\n";
    std::cout << "phone number : << " << entry.phone_number <<"\n";
    std::cout << "birth dat : " << entry.birth_day <<"\n";
    std::cout << "favorite meal : " << entry.fav_meal <<"\n";
    std::cout << "underwear color : " << entry.underwear_color <<"\n";
    std::cout << "darkest secret : " << entry.darkest_secret <<"\n";
    return ;
}

void    search_display(Contact contact_list[])
{
    int             i;
    int             index;
    std::string     input;

    i = 0;
    while (i < 8)
    {
        printf("|%10d|%10s|%10s|%10s|\n"
        ,i+1,contact_list[i].first_name.c_str(),contact_list[i].last_name.c_str(),contact_list[i].login.c_str());
        i++;
    }
    while (1)
    {
        std::cout << "Index ? ( 1 - 8)";
        std::getline(std::cin,input);
        index = input[0] - '0' + 1;
        if (index < 9 && index > 0)
        {
            display(contact_list[index]);
            return ;
        }
        else
            std::cout << "idiot\n";
    }
    return ;
}

int     main(void)
{
    std::string     input;
    Contact         contact_list[8];
    int             i;
    
    i = 0;
    std::cout << "Welcome to your PhoneBook\n";
    while (1)
    {
        std::cout << ">>";
        std::getline(std::cin,input);
        std::cout<<"//"<<input<<"\\\\\n";
        if (input.compare("ADD") == 0)
        {
            if (i == 7)
            {
                std::cout << "Max contact reached\n";
                break;
            }
            contact_list[i] = add_contact();
            i++;
        }
        else if (input.compare("SEARCH") == 0)
            search_display(contact_list);
        else if (input.compare("EXIT") == 0)
            return 0;
    }
}
