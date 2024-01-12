/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:22:02 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/11 10:38:38 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
			name("AForm"), _Signed(false), gradeToSign(0), gradeToExec(0)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign <= 0 || gradeToExec <= 0)
		throw GradeTooHighException();
}

Form::Form(const std::string _name, const int _gradeToSign, const int _gradeToExec) :
			name(_name), _Signed(false), gradeToSign(_gradeToSign), gradeToExec(_gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign <= 0 || gradeToExec <= 0)
		throw GradeTooHighException();
}

Form::Form(const Form& copy) :
				name(copy.name), _Signed(copy._Signed),
				gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec)
{
	this->operator=(copy);
}

Form&	Form::operator=(const Form& assign)
{
	_Signed = assign._Signed;
	return (*this);
}

Form::~Form()
{
}

const std::string&	Form::getName() const
{
	return (name);
}

bool	Form::getSigned() const
{
	return (_Signed);
}

int	Form::getGradeToSign() const
{
	return (gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (gradeToExec);
}

void	Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() <= gradeToSign)
		_Signed = true;
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("invalid grade (too low)");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("invalid grade (too high)");
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os  << "name : " << obj.getName() << "; "
		<< "getGradeToExec : " << obj.getGradeToExec() << "; " 
		<< "getGradeToSign : " << obj.getGradeToSign() << "; " 
		<< "getSigned : " << obj.getSigned();
	return	os;
}
