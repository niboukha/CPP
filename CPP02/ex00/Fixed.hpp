/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:54:34 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/25 16:39:24 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private :
		int					fixedValue;
		static const int	numFracBits;

	public :
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& fixed);
		Fixed&	operator=(const Fixed& fixed);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
