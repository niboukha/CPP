/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:14:19 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/11 10:53:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    AForm   *form = NULL;
    AForm   *form1 = NULL;
    AForm   *form2 = NULL;
    
    try
    {
        Bureaucrat  buro("game", 3);
        Intern      someRandomIntern;
        
        form  = someRandomIntern.makeForm("shrubbery creation", "tree");
        form1 = someRandomIntern.makeForm("robotomy request", "robot");
        form2 = someRandomIntern.makeForm("presidential pardon", "presidente");
        
        std::cout << buro << std::endl;
        
        buro.signForm(*form);
        buro.executeForm(*form);

        buro.signForm(*form1);
        buro.executeForm(*form1);
        
        buro.signForm(*form2);
        buro.executeForm(*form2);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exeption: " << e.what() << std::endl;
    }
    
    delete form;
    delete form1;
    delete form2;
    
    return(0);
}

