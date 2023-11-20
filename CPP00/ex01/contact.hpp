/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:07:26 by niboukha          #+#    #+#             */
/*   Updated: 2023/11/20 13:20:29 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class	Contact
{
	private :
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNum;
		std::string	darkestSecret;
		
	public :
			
		const std::string&	getFirstName() const;
		bool	setFirstName();
		
		const std::string&	getLastName() const;
		bool	setLastName();
		
		const std::string&	getNickname() const;
		bool	setNickname();
		
		const std::string&	getPhoneNum() const;
		bool	setPhoneNum();
		
		const std::string&	getDarkestSecret() const;
		bool	setDarkestSecret();
	
};

#endif
