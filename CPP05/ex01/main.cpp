/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:14:19 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/10 10:57:16 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form        form("ceo contract", 3, 3);
        Bureaucrat  bur("nisrin", 1);
        
        std::cout << bur << std::endl;
        std::cout << form << std::endl;

        bur.signForm(form);

        bur.low(bur);
        bur.low(bur);
    
        bur.signForm(form);
        
        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exeption: " << e.what() << std::endl;
    }
    return(0);
}
