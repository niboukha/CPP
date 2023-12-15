/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:49:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 11:23:48 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
    protected:
        std::string const  _type;

    public:
        AMateria();
        AMateria(const AMateria& amateria);
        AMateria&   operator=(const AMateria& amateria);   
        virtual	~AMateria();

        AMateria(std::string const & type);

        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif