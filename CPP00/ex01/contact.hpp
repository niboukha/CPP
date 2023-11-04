/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:07:26 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/30 11:29:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

class	Contact
{
	private :
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_num;
		std::string	darkest_secret;
		
	public :
			
		std::string	getFirst_name();
		void	setFirst_name(std::string &name);
		
		std::string	getLast_name();
		void	setLast_name(std::string &name);
		
		std::string	getNickname();
		void	setNickname(std::string &name);
		
		std::string	getPhone_num();
		void	setPhone_num(std::string &name);
		
		std::string	getDarkest_secret();
		void	setDarkest_secret(std::string &name);
		
		static void	trim_string(std::string &name);
		static void    check_input(std::string &name);
		
};

#endif
