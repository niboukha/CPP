/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:49:15 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 11:15:25 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& ice);
        Ice&   operator=(const Ice& ice);   
        ~Ice();
        
        AMateria* clone() const;
        void    use(ICharacter& target);
};

#endif
