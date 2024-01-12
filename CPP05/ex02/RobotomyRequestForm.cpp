/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:45:26 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/09 19:16:03 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 75, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) :
							AForm("Robotomy Request Form", 75, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : target(copy.target)
{
	this->operator=(copy);
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& assign)
{
	target = assign.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void    RobotomyRequestForm::robotAction() const
{
    srand(time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << " has been failed" << std::endl;       
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == true && executor.getGrade() <= getGradeToExec())
		robotAction();
	else if (getSigned() == false)
		throw GradeSignException();
	else
		throw GradeTooLowException();
}
