/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:17:52 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 10:08:15 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
    private :
        Brain   *brain;
    
    public :
    Cat(void);
    Cat(const Cat& cat);
    Cat&   operator=(const Cat& cat);
    virtual ~Cat(void);
    
    virtual void	makeSound() const;

    const std::string&  getCatIdea(int index) const;
    void                setCatIdea(std::string idea, int index);

};

#endif
