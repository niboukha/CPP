/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:58:58 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/12 16:09:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits.h>

class ScalarConverter
{
    public :

        static void         convert( std::string input );
        
        static void         charCast( std::string input );
        static void         intCast( std::string input );
        static void         floatCast( std::string input );
        static void         doubleCast( std::string input );
        
        static bool         isFloat( const std::string &str );
        static bool         isInt( const std::string &str );
        static bool         isChar( const std::string &str );
        static bool         isDouble( const std::string &str );
        static bool         isDigits( const std::string &str );

        static int          countPoints( const std::string &str );
        static bool         countF( const std::string &str );
        static bool         pseudoLiterals( const std::string &str );

        static bool         overflowInt(std::string input, int num);
        static bool         overflowfloat(int n, float num, size_t length);
        
        static void         impossibleConversion( void );
        
        static std::string  convertToFloatExpr( float num, size_t length );
        static std::string  convertToDoubleExpr( double num, size_t length );
};      

#endif
