/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:49:05 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 09:56:43 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class   Brain
{
    protected :
        std::string ideas[100];
        
    public :
        Brain(void);
        Brain(const Brain& brain);
        Brain&   operator=(const Brain& brain);
        ~Brain(void);

        const std::string&   getBrain(int index) const;
        void    setBrain(std::string idea, int index);
};

#endif
