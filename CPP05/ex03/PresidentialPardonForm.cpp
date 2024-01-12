/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:11:25 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/09 18:47:36 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) :
							AForm("Presidential Pardon Form", 25, 5), target(_target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : target(copy.target)
{
	this->operator=(copy);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assign)
{
	target = assign.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void    PresidentialPardonForm::presidentAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == true && executor.getGrade() <= getGradeToExec())
		presidentAction();
	else if (getSigned() == false)
		throw GradeSignException();
	else
		throw 	GradeTooLowException();
}
