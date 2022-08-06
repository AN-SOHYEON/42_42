/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: san <san@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:21:40 by san               #+#    #+#             */
/*   Updated: 2022/08/06 14:21:41 by san              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator 					iterator;
		// typedef typename std::stack<T>::container_type::const_iterator			iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator			reverse_iterator;
		// typedef typename std::stack<T>::container_type::const_reverse_iterator	reverse_iterator;

		MutantStack();
		MutantStack(const MutantStack &ms);
		MutantStack &operator=(const MutantStack &ms);
		virtual ~MutantStack();

		iterator begin();
		iterator end();
		// const_iterator cbegin() const;
		// const_iterator cend() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		// const_reverse_iterator crbegin() const;
		// const_reverse_iterator crend() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &ms) 
{
	*this = ms;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &ms) 
{
	if (this != &ms)
	{
		this->c = ms.c;
	}
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() 
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() 
{
	return this->c.end();
}

// template <typename T>
// typename MutantStack<T>::const_iterator MutantStack<T>::begin() const 
// { return this->c.begin(); }

// template <typename T>
// typename MutantStack<T>::const_iterator MutantStack<T>::end() const 
// { return this->c.end(); }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() 
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() 
{
	return this->c.rend();
}

// template <typename T>
// typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const 
// { return this->c.rbegin(); }

// template <typename T>
// typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const 
// { return this->c.rend(); }

#endif
