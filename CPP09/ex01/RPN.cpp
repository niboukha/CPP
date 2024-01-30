/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:40:53 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/21 15:30:15 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	(void)copy;
}

RPN::~RPN()
{
}

RPN&    RPN::operator=( const RPN& assign )
{
	(void)assign;
	return (*this);
}

const char*	RPN::InvalidInput::what() const throw()
{
	return ("Error.");
}

const char*	RPN::DivZero::what() const throw()
{
	return ("Invalid operation division by Zero.");
}

bool    RPN::isNumber(const std::string &input)
{
    std::size_t found = input.find_first_not_of("0123456789");
    
    if (found == std::string::npos and input.length() == 1)
        return (true);
    return (false);
}

bool    RPN::isOperator(const std::string &input)
{
    std::size_t found = input.find_first_not_of("+-/*");
    
    if (found == std::string::npos and input.length() == 1)
        return (true);
    return (false);
}

void    RPN::rPolishNotation(std::stack<int> &stack, const std::string &input)
{
    int     a;
    int     b;
    int     result;
    char    ch;

    if (isOperator(input) == true or isNumber(input) == true)
    {
        ch = input[0];

        switch (ch)
        {
            case '+':
                if (stack.size() >= 2)
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    result = a + b;
                    stack.push(result);
                }
                else
                    throw InvalidInput();
                break;
            case '-':
                if (stack.size() >= 2)
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    result = b - a;
                    stack.push(result);
                }
                else
                    throw InvalidInput();
                break;
            case '*':
                if (stack.size() >= 2)
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    result = a * b;
                    stack.push(result);
                }
                else
                    throw InvalidInput();
                break;
            case '/':
                if (stack.size() >= 2)
                {
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    if (a == 0)
                        throw DivZero();
                    result = b / a;
                    stack.push(result);
                }
                else
                    throw InvalidInput();
                break;
            default :
                stack.push(std::atoi(input.c_str()));
                break;
        }
    }
    else
        throw InvalidInput();
}
