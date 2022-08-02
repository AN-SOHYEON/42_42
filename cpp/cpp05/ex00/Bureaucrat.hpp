

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat	&operator=(const Bureaucrat &bureaucrat);

		const std::string	getName() const;
		int					getGrade() const;
		void				upGrade();
		void				downGrade();

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

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
