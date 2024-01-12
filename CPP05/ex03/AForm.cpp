/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:02 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/11 10:39:06 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :
			name("def"), _Signed(false), gradeToSign(0), gradeToExec(0)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign <= 0 || gradeToExec <= 0)
		throw GradeTooHighException();
}

AForm::AForm(const std::string _name, const int _gradeToSign, const int _gradeToExec) :
			name(_name), _Signed(false), gradeToSign(_gradeToSign), gradeToExec(_gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign <= 0 || gradeToExec <= 0)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& copy) :
				name(copy.name), _Signed(copy._Signed),
				gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec)
{
	this->operator=(copy);
}

AForm&	AForm::operator=(const AForm& assign)
{
	_Signed = assign._Signed;
	return (*this);
}

AForm::~AForm()
{
	
}

const std::string&	AForm::getName() const
{
	return (name);
}

bool	AForm::getSigned() const
{
	return (_Signed);
}

int	AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (gradeToExec);
}

void	AForm::beSigned(Bureaucrat const &obj)
{
	if (obj.getGrade() <= gradeToSign)
		_Signed = true;
	else
		throw GradeTooLowException();
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("invalid grade (too low)");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("invalid grade (too high)");
}

const char*	AForm::GradeSignException::what() const throw()
{
	return ("Form Not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os  << "name : " << obj.getName() << "; "
		<< "getGradeToExec : " << obj.getGradeToExec() << "; " 
		<< "getGradeToSign : " << obj.getGradeToSign() << "; " 
		<< "getSigned : " << obj.getSigned();
	return	os;
}
