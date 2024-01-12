/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:55:47 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/10 10:18:34 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
	{
		private :
			const std::string	name;
			bool				_Signed;
			const int			gradeToSign;
			const int			gradeToExec;

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
			
			public :
				Form();
				Form(const std::string _name, const int _gradeToSign, const int _gradeToExec);
				Form(const Form& copy);
				~Form();

				Form& operator=(const Form& assign);
					
				const std::string&	getName() const;
				bool				getSigned() const;
				int					getGradeToSign() const;
				int					getGradeToExec() const;
				
				void				beSigned(const Bureaucrat &obj);
	};
	
	std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
