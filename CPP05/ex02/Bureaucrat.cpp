/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:14:14 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/11 10:39:46 by niboukha         ###   ########.fr       */
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

const char*	Bureaucrat::ExecutionException::what() const throw()
{
	return ("Bureaucrat doesn't execute the form");
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << name << " couldn’t sign " << form.getName() <<  " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;	
	}
	catch (std::exception & e)
	{
		std::cout << name << " couldn’t execute " << form.getName() <<  " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << " , bureaucrat grade " << obj.getGrade() <<  '.' ;
	return	os;
}
