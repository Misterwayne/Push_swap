/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:01:57 by mwane             #+#    #+#             */
/*   Updated: 2020/07/08 19:16:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#   ifndef _HUMAN_H_
#   define _HUMAN_H_
#include "Brain.hpp"

class Human{
    public:
        Brain           veaucer;
        Brain*          identify(void);
};

#   endif

