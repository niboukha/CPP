/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:35:10 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/07 18:16:46 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class	Harl
{
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	
	public :
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
