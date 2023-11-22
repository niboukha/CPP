/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:24:01 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/21 17:43:00 by niboukha         ###   ########.fr       */
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
		Fixed	(void);
		Fixed	(const int value);
		Fixed	(const float value);
		~Fixed(void);
		Fixed	(const Fixed& copy);
		
		Fixed&		operator=(const Fixed& fixed);

		bool		operator>(const Fixed& fixed) const;
		bool		operator<(const Fixed& fixed) const;
		bool		operator>=(const Fixed& fixed) const;
		bool		operator<=(const Fixed& fixed) const;
		bool		operator==(const Fixed& fixed) const;
		bool		operator!=(const Fixed& fixed) const;

		Fixed		operator+(Fixed const& fixed) const;
		Fixed		operator-(Fixed const& fixed) const;
		Fixed		operator*(Fixed const& fixed) const;
		Fixed		operator/(Fixed const& fixed) const;
		
		Fixed&		operator--();				// pre --a
		Fixed&		operator++();				//pre ++a
		Fixed		operator--(int);	// post a--
		Fixed		operator++(int);	//post a++
		
		float		toFloat(void) const;
		int			toInt(void) const;
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		
		static Fixed&	min(Fixed& fstFixed, Fixed& secFixed);
		static Fixed&	max(Fixed& fstFixed, Fixed& secFixed);

		static const Fixed&	min(const Fixed& fstFixed, const Fixed& secFixed);
		static const Fixed&	max(const Fixed& fstFixed, const Fixed& secFixed);
		
	};

	std::ostream& operator<<(std::ostream& os, const Fixed& obj);

	#endif
