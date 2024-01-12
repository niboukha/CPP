/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:55:47 by niboukha          #+#    #+#             */
/*   Updated: 2024/01/09 18:57:46 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
	{
		private :
			const std::string	name;
			bool				_Signed;
			const int			gradeToSign;
			const int			gradeToExec;
		
		protected :
		
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
			class	GradeSignException : public std::exception
			{
				public :
					const char	*what() const throw();
			};
			
			public :
				AForm();
				AForm(const std::string _name, const int _gradeToSign, const int _gradeToExec);
				AForm(const AForm& copy);
				virtual ~AForm();

				AForm& operator=(const AForm& assign);
					
				const std::string&	getName() const;
				bool				getSigned() const;
				int					getGradeToSign() const;
				int					getGradeToExec() const;
				void				beSigned(Bureaucrat const &obj);

				virtual void	execute(Bureaucrat const & executor) const = 0;
				
	};
	std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
