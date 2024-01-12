/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:58:55 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/12 18:59:41 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int  ScalarConverter::countPoints( const std::string &str )
{
	int count = 0;
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if(str[i] == '.')
			count++;
	}
	return (count);
}

bool  ScalarConverter::countF( const std::string &str )
{
	int count = 0;
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if(str[i] == 'f')
			count++;
	}
	return (count == 1 and str[str.length() - 1] == 'f');
}

bool    ScalarConverter::isDigits( const std::string &str )
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

bool ScalarConverter::isInt( const std::string &str )
{
	return (isDigits(str)
			or ((str[0] == '+' or str[0] == '-') and isDigits(str.substr(1))));
}

bool ScalarConverter::isChar( const std::string &str )
{
	return (str.length() == 1 and std::isprint(str[0]) and isDigits(str) == false);
}

bool  ScalarConverter::pseudoLiterals( const std::string &str )
{
	return (!str.compare("nan") or !str.compare("-inf") or !str.compare("+inf")
		or !str.compare("nanf") or !str.compare("-inff") or !str.compare("+inff"));
}

bool ScalarConverter::isFloat( const std::string &str )
{
	if ((str.find_first_not_of("0123456789.f") == std::string::npos
		and countF(str)
		and countPoints(str) == 1)
		or ((str[0] == '+' or str[0] == '-')
		and str.substr(1).find_first_not_of("0123456789.f") == std::string::npos
		and countF(str.substr(1))
		and countPoints(str.substr(1)) == 1))
		return (true);
	else if (!str.compare("-inff") or !str.compare("+inff") or !str.compare("nanf"))
		return (true);
	return (false);
}

bool ScalarConverter::isDouble( const std::string &str )
{
	if ((str.find_first_not_of("0123456789.") == std::string::npos
		and countPoints(str) == 1)
		or ((str[0] == '+' or str[0] == '-')
		and str.substr(1).find_first_not_of("0123456789.") == std::string::npos
		and countPoints(str.substr(1)) == 1))
		return (true);
	else if (!str.compare("-inf") or !str.compare("+inf") or !str.compare("nan"))
		return (true);
	return (false);
}

std::string ScalarConverter::convertToFloatExpr( float num, size_t length )
{
	std::string         str;
	std::string         s;
	std::stringstream   toFloat;
	
	toFloat << std::setprecision(length);
	toFloat << num;
	toFloat >> str;
	if (!str.compare("nan") or !str.compare("-inf") or !str.compare("inf"))
		return (s += 'f');
	if (str.find_first_of(".") != std::string::npos)
		s += 'f';
	else
		s += ".0f";
	return (s);
}

std::string ScalarConverter::convertToDoubleExpr( double num, size_t length )
{
	std::stringstream   toDouble;
	std::string         str;
	std::string         s;

	toDouble << std::setprecision(length);
	toDouble << num;
	toDouble >> str;
	if (!str.compare("nan") or !str.compare("-inf") or !str.compare("inf"))
		return (s);
	if (str.find_first_of(".") == std::string::npos)
		s += ".0";
	return (s);
}

void ScalarConverter::charCast( std::string input )
{
	char    c;

	c = input[0];
	std::cout << "char: '" << static_cast <char> (c) << "'" << std::endl;
	std::cout << "int: " << static_cast <int> (c) << std::endl; 
	std::cout << "float: " << std::setprecision(input.length()) << static_cast <float> (c)
		<< convertToFloatExpr(static_cast <float> (c), input.length()) << std::endl;
	std::cout << "double: " << std::setprecision(input.length()) << static_cast <double> (c)
		<< convertToDoubleExpr(static_cast <double> (c), input.length()) << std::endl; 
}

bool ScalarConverter::overflowInt(std::string input, int num)
{
	std::stringstream   toString;
	std::string			s;

	toString << num;
	toString >> s;
	if (!s.compare(input))
		return (true);
	return (false);	
}

void ScalarConverter::intCast( std::string input )
{
	int	num;

	num = std::atoi(input.c_str());
	
	if (!overflowInt(input, num))
		impossibleConversion();
	else
	{
		if (std::isprint(static_cast <char> (num)) and num <= CHAR_MAX and num >= CHAR_MIN)
			std::cout << "char: '" << static_cast <char> (num) << "'" << std::endl;
		else if (!std::isprint(static_cast <char> (num)) and num <= CHAR_MAX and num >= CHAR_MIN)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << static_cast <int> (num) << std::endl;
		std::cout << "float: " << std::setprecision(input.length()) << static_cast<float> (num) << convertToFloatExpr(static_cast <float> (num), input.length()) << std::endl;
		std::cout << "double: " << std::setprecision(input.length()) << static_cast <double> (num) << convertToDoubleExpr(static_cast <double> (num), input.length()) << std::endl; 	
	}
}

bool ScalarConverter::overflowfloat(int n, float num, size_t length)
{
	std::stringstream   toString;
	std::stringstream   ts;
	std::string			s;
	std::string			str;
	
	toString << std::setprecision(length);
	toString << num;
	toString >> s;
	ts << n;
	ts >> str;
	if (str.compare(s))
		return (true);
	return (false);	
}

void ScalarConverter::floatCast( std::string input )
{
	float	num;
	
	num = std::atof(input.c_str());
	if (pseudoLiterals(input) or num > INT_MAX or num < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (std::isprint(static_cast <char> (num)) and num <= CHAR_MAX and num >= CHAR_MIN)
			std::cout << "char: '" << static_cast <char> (num) << "'" << std::endl;
		else if (!std::isprint(static_cast <char> (num)) and num <= CHAR_MAX and num >= CHAR_MIN)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << static_cast <int> (num) << std::endl;
	}
	std::cout << "float: " << std::setprecision(input.length()) << static_cast <float> (num)
		<< convertToFloatExpr(static_cast <float> (num), input.length()) << std::endl;
	std::cout << "double: " << std::setprecision(input.length()) << static_cast <double> (num)
		<< convertToDoubleExpr(static_cast <double> (num), input.length()) << std::endl;
}

void ScalarConverter::doubleCast( std::string input )
{
	double num;

	num = std::strtod(input.c_str(), NULL);
	if (pseudoLiterals(input) or num > INT_MAX or num < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (std::isprint(static_cast <char> (num)) and num <= CHAR_MAX and num >= CHAR_MIN)
			std::cout << "char: '" << static_cast <char> (num) << "'" << std::endl;
		else if (!std::isprint(static_cast <char> (num)) and num <= CHAR_MAX and num >= CHAR_MIN)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << static_cast <int> (num) << std::endl;
	}
	std::cout << "float: " << std::setprecision(input.length()) << static_cast <float> (num)
		<< convertToFloatExpr(static_cast <float> (num), input.length()) << std::endl;
	std::cout << "double: " << std::setprecision(input.length()) << static_cast <double> (num)
		<< convertToDoubleExpr(static_cast <double> (num), input.length()) << std::endl; 
}

void ScalarConverter::impossibleConversion( void )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl; 
	std::cout << "float: impossible" << std::endl; 
	std::cout << "double: impossible" << std::endl; 
}

void ScalarConverter::convert( std::string input )
{
	if (isChar(input))
		charCast(input);
	else if (isInt(input))
		intCast(input);
	else if (isFloat(input))
		floatCast(input);
	else if (isDouble(input))
		doubleCast(input);
	else
		impossibleConversion();
}
