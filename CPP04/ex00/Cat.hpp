/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:17:52 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 15:19:26 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class   Cat : public Animal
{
    public :
        Cat(void);
        Cat(const Cat& cat);
        Cat&   operator=(const Cat& cat);
        ~Cat(void);
        
        virtual void	makeSound() const;  
};

#endif
