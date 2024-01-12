/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:14:14 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/11 10:37:49 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("niserin"), grade(-1)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= 0)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) :
				name(_name), grade(_grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade <= 0)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : 
	name(copy.name), grade(copy.grade)
{
	this->operator=(copy);
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& assign)
{
	grade = assign.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string&	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::high(Bureaucrat& obj)
{
	if (obj.grade > 1)
		obj.grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::low(Bureaucrat& obj)
{
	if (obj.grade < 150)
		obj.grade++;
	else
		throw GradeTooLowException();
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("invalid grade (too low)");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("invalid grade (too high)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << " , bureaucrat grade " << obj.getGrade() <<  '.' ;
	return	os;
}
