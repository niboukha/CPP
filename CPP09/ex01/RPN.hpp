/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:40:51 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/21 15:28:31 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class RPN
{
    private:

        RPN();
		RPN(const RPN &copy);
		RPN&    operator=( const RPN& assign );
        ~RPN();
		
        class	DivZero : public std::exception
		{
			public :
				const char	*what() const throw();
		};
        
    public:
	
        static void rPolishNotation(std::stack<int> &stack, const std::string &input);
        static bool isNumber(const std::string &input);
        static bool isOperator(const std::string &input);
     
        class	InvalidInput : public std::exception
		{
			public :
				const char	*what() const throw();
		};
		
};



#endif
