/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:37:25 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/21 15:28:06 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>

class BitcoinExchange
{
	private :
		
		std::map<std::string, std::string>	dataBase;

		class	FileFormat : public std::exception
		{
			public :
					const char	*what() const throw();
		};
		
		class	FileData : public std::exception
		{
			public :
					const char	*what() const throw();
		};

		class	DataValue : public std::exception
		{
			public :
					const char	*what() const throw();
		};

		class	ValidNumber : public std::exception
		{
			public :
					const char	*what() const throw();
		};

		class	PositiveValue : public std::exception
		{
			public :
					const char	*what() const throw();
		};

		class	TooLargNumber : public std::exception
		{
			public :
					const char	*what() const throw();
		};

		class	DateInDB : public std::exception
		{
			public :
					const char	*what() const throw();
		};

		class	LeadingZero : public std::exception
		{
			public :
					const char	*what() const throw();
		};
		
    public :
	
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		BitcoinExchange&    operator=( const BitcoinExchange& assign );
		~BitcoinExchange();
	
		static void	parseFirstLine(std::string &input);

		void	storeFisrtDataBase(std::map<std::string, std::string>	&dataBase);  
		void	displayResult(std::string &input);
		
		std::pair<std::string, std::string>	parseLineOfsecondDataBase(std::string &input);
		
		void	validDate(std::string date);
		void	leapYearValidation(std::string &date);
		bool 	dateLowThanFirstInDB(std::string dateFDB, std::string dateSDB);
		bool	checkIfLowThanFirstInDB(std::string dateFDB, std::string dateSDB);

		void	checkDateLength(std::string &str);


		void	validValue(std::string value);
		bool	isNumber( const std::string &value );
		bool	countF( const std::string &value );
		bool 	countPipes( const std::string &value);
		int  	countPoints( const std::string &value );

		class	ArgumentException : public std::exception
		{
			public :
				const char	*what() const throw();
		};

		class	fileException : public std::exception
		{
			public :
					const char	*what() const throw();
		};
};

#endif
