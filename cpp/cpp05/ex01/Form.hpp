
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class	Form
{
	private:
		const std::string	name;
		bool				is_signed;
		int					sign_grade;
		int					exe_grade;
	public:
		Form();
		~Form();
		Form(std::string name, int grade);
		Form(const Form &bureaucrat);
		Form	&operator=(const Form &bureaucrat);

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;


		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

};

std::ostream	&operator<<(std::ostream &out, const Form &bureaucrat);

#endif
