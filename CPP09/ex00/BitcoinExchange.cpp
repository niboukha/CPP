/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:37:27 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/20 20:09:05 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	storeFisrtDataBase(dataBase);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->operator=(copy);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange&    BitcoinExchange::operator=( const BitcoinExchange& assign )
{
	dataBase = assign.dataBase;
	return (*this);
}

const char*	BitcoinExchange::FileFormat::what() const throw()
{
	return ("Invalid File Format.");
}

const char*	BitcoinExchange::FileData::what() const throw()
{
	return ("Error: bad input ");
}

const char*	BitcoinExchange::PositiveValue::what() const throw()
{
	return ("Error: not a positive number.");
}

const char*	BitcoinExchange::ValidNumber::what() const throw()
{
	return ("Error: not valid number.");
}

const char*	BitcoinExchange::TooLargNumber::what() const throw()
{
	return ("Error: too large a number.");
}

const char*	BitcoinExchange::fileException::what() const throw()
{
	return ("Error: Could not open file.");
}

const char*	BitcoinExchange::ArgumentException::what() const throw()
{
	return ("Error: Invalid Arguments.");
}

const char*	BitcoinExchange::DateInDB::what() const throw()
{
	return ("Error: Date less than the exist in Data Base.");
}

const char*	BitcoinExchange::LeadingZero::what() const throw()
{
	return ("Error: Leading Zero.");
}

void	BitcoinExchange::parseFirstLine(std::string &input)
{
	if (input.compare("date | value"))
		throw FileFormat();
}

void	BitcoinExchange::storeFisrtDataBase(std::map<std::string, std::string>	&dataBase)
{
	std::string							readFile;
	int									pos;
    std::ifstream						file("data.csv");
	
	if (!file.is_open())
		throw fileException();
	pos = 0;
	std::getline (file, readFile);
	while (std::getline (file, readFile))
	{
		pos = readFile.find(",");
		dataBase[readFile.substr(0, pos)] = readFile.substr(pos + 1);
	}
	file.close();
}

void	BitcoinExchange::checkDateLength(std::string &str)
{
	if (str.find_first_not_of("0987654321") != std::string::npos)
		throw FileData();
}

void	BitcoinExchange::leapYearValidation(std::string &date)
{
	int					year;
	int					month;
	int					day;
	std::string 		str;
	std::stringstream	y;
	std::stringstream	d;
	std::stringstream	m;

	str = date.substr(0, 4);
	y << str;
	y >> year;
	checkDateLength(str);
	str.clear();
	str = date.substr(5, 2);
	m << str;
	m >> month;
	checkDateLength(str);
	str.clear();
	str = date.substr(8, 2);
	d << str;
	d >> day;
	checkDateLength(str);
	
	if (day == 0)
		throw FileData();
	if (((month == 2) and ((year % 400 == 0) or ((year % 100 != 0) and (year % 4 == 0)))) and day >= 30)
		throw FileData();
	else if (((month == 2) and !((year % 400 == 0) or ((year % 100 != 0) and (year % 4 == 0)))) and day >= 29)
		throw FileData();
	else if ((month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12) and day > 31)
		throw FileData();
	else if ((month == 4 or month == 6 or month == 9 or month == 11) and day > 30)
		throw FileData();
}

void    BitcoinExchange::validDate(std::string date)
{
	struct tm	tm;

	if (date.length() != 11 or date[date.length() - 1] != ' ' or !strptime(date.substr(0, 10).c_str(), "%Y-%m-%d", &tm))
		throw FileData();
	leapYearValidation(date);
}

int  BitcoinExchange::countPoints( const std::string &str )
{
	int count = 0;
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if(str[i] == '.')
			count++;
	}
	return (count);
}

bool  BitcoinExchange::isNumber( const std::string &value )
{
	if (value.find_first_not_of("+-.") == std::string::npos)
		return (false);
	if ((value.find_first_not_of("0123456789.") == std::string::npos
		and (countPoints(value) == 1 or countPoints(value) == 0))
		or ((value[0] == '+' or value[0] == '-')
		and value.substr(1).find_first_not_of("0123456789.") == std::string::npos
		and (countPoints(value) == 1 or countPoints(value) == 0)))
		return (true);
	return (false);
}

void    BitcoinExchange::validValue(std::string value)
{
	std::string	val;
	std::string	s;
	float		f;
	
	f = 0.0;
	if (value[0] != ' ')
		throw FileFormat();
	s += value.substr(1);
	for(size_t i = 1 ; i < value.length(); i++)
	{
		if (value[i] == '.')
			break;
		val += value[i];
	}
	if (isNumber(s) == true)
	{
		if (val[0] == '0' and val.size() > 1)
			throw	LeadingZero();
		f = static_cast <float> (std::atof(s.c_str()));
		if (s[0] == '-')
			throw	PositiveValue();
		if (f > 1000 or val.length() > 4)
			throw	TooLargNumber();
	}
	else
		throw ValidNumber();
}

bool BitcoinExchange::countPipes( const std::string &value)
{
	int	val;

	val = 0;
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '|')
			val++;	
	}
	if (val == 1)
		return (true);
	return (false);
}

std::pair<std::string, std::string>	BitcoinExchange::parseLineOfsecondDataBase(std::string &input)
{
	std::pair<std::string, std::string>	line;
	std::size_t							found;
	
	try 
	{
		if (input.empty())
			throw FileFormat();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (line);
	}
	
	found = input.find_first_of("|");
	try
	{
		validDate(input.substr(0, found));
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "=> " << input.substr(0, found) << "\n";
			return (line);
	}
	
	try
	{
		if (countPipes(input) == false)
			throw FileFormat();
		if (input.substr(found + 1, input.size()).empty())
			throw FileFormat();
		validValue(input.substr(found + 1, input.size()));
		line = std::make_pair(input.substr(0, found - 1), input.substr(found + 2));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (line);
	}
	return (line);
}

bool BitcoinExchange::dateLowThanFirstInDB(std::string dateFDB, std::string dateSDB)
{
	if (dateFDB.substr(0, 4) != (dateSDB.substr(0, 4)))
	{
		if (dateFDB.substr(0, 4) > dateSDB.substr(0, 4))
			return (true);
		return (false);
	}

	if (dateFDB.substr(5, 2) != (dateSDB.substr(5, 2)))
	{
		if (dateFDB.substr(5, 2) > dateSDB.substr(5, 2))
			return (true);
		return (false);
	}
	
	if (dateFDB.substr(8, 2) > dateSDB.substr(8, 2))
		return (true);	

	return (false);
}

void    BitcoinExchange::displayResult(std::string &input)
{
	std::pair<std::string, std::string>				line;
	std::map<std::string, std::string>:: iterator	itData;
	std::map<std::string, std::string>:: iterator	it;
	std::string										str;

	try
	{
		line = parseLineOfsecondDataBase(input);
		if (line.first.size() == 0)
			return ;

		itData = dataBase.lower_bound(line.first);
		it = dataBase.begin();
		if (dateLowThanFirstInDB(it->first, line.first))
			throw DateInDB();

		if (itData != dataBase.end() and itData->first != line.first)
			itData--;

		if (itData != dataBase.end())
			std::cout << line.first << " => " << line.second << " = " 
				<< static_cast <float> (std::atof(itData->second.c_str())) * static_cast <float> (std::atof(line.second.c_str())) 
				<< std::endl;
		else
		{
			itData--;
			std::cout << line.first << " => " << line.second << " = " 
				<< static_cast <float> (std::atof(itData->second.c_str())) * static_cast <float> (std::atof(line.second.c_str())) 
				<< std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
