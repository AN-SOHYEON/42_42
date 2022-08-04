
#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		const std::string	name;
		bool				is_signed;
		int					sign_grade;
		int					exe_grade;
	public:
		Form();
		virtual	~Form();
		Form(std::string name, bool is_signed, int sign_grade, int exe_grade);
		Form(const Form &form);
		Form	&operator=(const Form &form);

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExeGrade() const;
		void				beSigned(Bureaucrat &form);
		virtual void		execute(const Bureaucrat &bureaucrat) const = 0;

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

		class	FormIsNotSigned : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	FailToExecute : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif
