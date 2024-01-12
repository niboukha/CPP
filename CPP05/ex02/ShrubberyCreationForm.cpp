/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:48:37 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/09 18:55:08 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : 
							AForm("Shrubbery Creation Form", 145, 137) , target(_target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : target(copy.target)
{
	this->operator=(copy);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assign)
{
	target = assign.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::shrubberyAction() const
{
	std::string		fileName = target + "_shrubbery";
	std::ofstream	outFile(fileName.c_str());
	
	if (!outFile.is_open())
		throw fileException();
	else
	{
		outFile << "          .     .  .      +     .      .          ." << std::endl;
		outFile << "     .       .      .     #       .           ." << std::endl;
		outFile << "        .      .         ###            .      .      ." << std::endl;
		outFile << "      .      .   '#:. .:####:. .:#'  .      ." << std::endl;
		outFile << "          .      . '####'###'####'  ." << std::endl;
		outFile << "       .     '#:.    .:#'###'#:.    .:#'  .        .       ." << std::endl;
		outFile << "  .             '#########'#########'        .        ." << std::endl;
		outFile << "        .    '#:.  '####'###'####'  .:#'   .       ." << std::endl;
		outFile << "     .     .  '#######'##'##'#######'                  ." << std::endl;
		outFile << "                .'##'#####'#####'##'           .      ." << std::endl;
		outFile << "    .   '#:. ...  .:##'###'###'##:.  ... .:#'     ." << std::endl;
		outFile << "      .     '#######'##'#####'##'#######'      .     ." << std::endl;
		outFile << "    .    .     '#####'#######'#####'    .      ." << std::endl;
		outFile << "            .     '      000      '    .     ." << std::endl;
		outFile << "       .         .   .   000     .        .       ." << std::endl;
		outFile << ".. .. ..................O000O........................ ...... ..." << std::endl;
		
		outFile.close();
	}
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == true && executor.getGrade() <= getGradeToExec())
		shrubberyAction();
	else if (getSigned() == false)
		throw GradeSignException();
	else
		throw GradeTooLowException();
}

const char*	ShrubberyCreationForm::fileException::what() const throw()
{
	return ("Wasn't successfully opened.");
}
