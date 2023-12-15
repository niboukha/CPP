/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:01:52 by niboukha          #+#    #+#             */
/*   Updated: 2023/12/02 11:23:36 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private :
        std::string const name;
        AMateria    *slots[4];
		
		class	GbColl
		{
			public :
				AMateria	*val;
				GbColl		*next;
				GbColl(AMateria *value);
				GbColl();
				GbColl(const GbColl& gbcoll);
				GbColl&  operator=(const GbColl& gbcoll);
				~GbColl();
				static	void	addFront(GbColl **head, GbColl *newVal);
				static	void	freeAll(GbColl **head);
				static GbColl	*front;
		};

	public:
		Character();
		Character(const Character& character);
        Character&  operator=(const Character& character);
		~Character();
		
		Character(std::string const & _name);

		
		std::string const & getName() const;
		
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
