/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:26:30 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/08 10:32:24 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

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
		void	write_levels(int i);
};

#endif
