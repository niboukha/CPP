/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:14:16 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/11 10:37:28 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <ctime>
#include <iostream>

#include "AForm.hpp"
class AForm;

class Bureaucrat
	{
		private :
			const std::string	name;
			int					grade;

			class	GradeTooHighException : public std::exception
			{
				public :
					const char	*what() const throw();

			};
			class	GradeTooLowException : public std::exception
			{
				public :
					const char	*what() const throw();
			};
			class	ExecutionException : public std::exception
			{
				public :
					const char	*what() const throw();
			};
			
		public :
			Bureaucrat();
			Bureaucrat(const std::string _name, int _grade);
			Bureaucrat(const Bureaucrat& copy);
			~Bureaucrat();
			
			Bureaucrat& operator=(const Bureaucrat& assign);
			
			const std::string&	getName() const;
			int					getGrade() const;
			void				high(Bureaucrat& obj);
			void				low(Bureaucrat& obj);

			void				signForm(AForm &form);
			void				executeForm(AForm const & form);
	};
	std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
