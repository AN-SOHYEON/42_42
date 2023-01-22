#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	// template <class T, class Container>
	template <class T, class Container = ft::vector<T> >
	class stack
	{

	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

	protected:
		container_type _content;

	public:
		explicit stack(const Container &cont = Container())
		{
			// _content = vector(Alloc);
			_content = cont;
			// std::cout << "stack constructor\n";
		}

		virtual ~stack()
		{
			// TODO: 벡터 소멸자에 destroy랑 deallocate있느니까 안해도 되지 않나?
		}

		stack &operator=(const stack &other)
		{
			_content = other._content;
			return (*this);
		}

		reference top()
		{
			return (_content.back());
		}

		const_reference top() const
		{
			return (_content.back());
		}

		bool empty() const
		{
			if (_content.empty())
				return true;
			return false;
		}

		size_type size() const
		{
			return (_content.size());
		}

		void push(const value_type &value)
		{
			_content.push_back(value);
		}

		void pop()
		{
			_content.pop_back();
		}

		friend bool operator==(const stack &lhs, const stack &rhs)
		{
			// std::cout << "here\n";
			return (lhs._content == rhs._content);
		}

		friend bool operator!=(const stack &lhs, const stack &rhs)
		{
			return !(lhs == rhs);
		}

		friend bool operator<(const stack &lhs, const stack &rhs)
		{
			return (lhs._content < rhs._content);
		}

		friend bool operator<=(const stack &lhs, const stack &rhs)
		{
			return (lhs._content <= rhs._content);
		}

		friend bool operator>(const stack &lhs, const stack &rhs)
		{
			return (lhs._content > rhs._content);
		}

		friend bool operator>=(const stack &lhs, const stack &rhs)
		{
			return (lhs._content >= rhs._content);
		}
	};

	// template <class T, class Container>
	// bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	// {
	// 	// std::cout << "here\n";
	// 	return (lhs.content == rhs.content);
	// }

	// template <class T, class Container>
	// bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	// {
	// 	return !(lhs == rhs);
	// }

	// template <class T, class Container>
	// bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	// {
	// 	return (lhs.content < rhs.content);
	// }

	// template <class T, class Container>
	// bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	// {
	// 	return (lhs.content <= rhs.content);
	// }

	// template <class T, class Container>
	// bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	// {
	// 	return (lhs.content > rhs.content);
	// }

	// template <class T, class Container>
	// bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	// {
	// 	return (lhs.content >= rhs.content);
	// }
}

#endif