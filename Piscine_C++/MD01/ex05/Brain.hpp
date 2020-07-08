/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:45:23 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 19:03:29 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#	ifndef _BRAIN_H_
#	define _BRAIN_H_
#include <iostream>
#include <string>
#include <memory>

class Brain{
	public:
		int             iq;
		int             size;
		std::string		type;
		Brain*			identify(void);
};

#	endif