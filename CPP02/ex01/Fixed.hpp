/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:11:20 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/27 12:36:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private :
		int					fixedValue;
		static const int	numFracBits;

	public :
		Fixed (void);
		Fixed (const Fixed& copy);
		Fixed&	operator=(const Fixed& fixed);
		~Fixed(void);
		
		Fixed (const int value);
		Fixed (const float value);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
