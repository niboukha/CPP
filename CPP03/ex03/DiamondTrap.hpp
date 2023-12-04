/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:39:18 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/01 12:15:39 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public  FragTrap, public ScavTrap
{
    private :
        std::string name;
    
    public :
        DiamondTrap(void);
        DiamondTrap(const DiamondTrap& diamondtrap);
        DiamondTrap& operator=(const DiamondTrap& diamondtrap);
        ~DiamondTrap(void);

        DiamondTrap(std::string _name);

        void	attack(const std::string& target);
        void    whoAmI();
};

#endif
