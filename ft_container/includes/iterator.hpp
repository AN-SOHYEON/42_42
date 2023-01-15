#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <algorithm>

namespace ft
{

	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type; // iterator가 가리키는 타입
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <typename T>
	struct iterator_traits<T *>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type; // iterator가 가리키는 타입
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T *>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type; // iterator가 가리키는 타입
		typedef const T *pointer;
		typedef const T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <typename Iterator>
	class reverse_iterator
	{
	protected:
		Iterator current;

	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;

		reverse_iterator() : current() {}

		explicit reverse_iterator(iterator_type x)
		{
			current = x;
		}

		template <typename U>
		reverse_iterator(const reverse_iterator<U> &other)
		{
			current = other.base();
		}

		template <typename U>
		reverse_iterator &operator=(const reverse_iterator<U> &other)
		{
			current = other.base();
			return *this;
		} ///????????????????????????????

		// 기본 반복자 반환
		Iterator base() const
		{
			return current;
		}

		reference operator*() const
		{
			Iterator tmp = current;
			return *--tmp;
		}

		pointer operator->() const
		{
			return std::addressof(operator*());
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

		reverse_iterator &operator++()
		{
			--current;
			return *this;
		}
		reverse_iterator operator++(int)
		{ // 후위 연산자
			reverse_iterator tmp(*this);
			--current;
			return tmp;
		}

		reverse_iterator &operator--()
		{
			++current;
			return *this;
		}
		reverse_iterator operator--(int)
		{ // 후위 연산자
			reverse_iterator tmp(*this);
			++current;
			return tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(current - n);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(current + n);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			current -= n;
			return *this;
		}

		reverse_iterator &operator-=(difference_type n)
		{
			current += n;
			return *this;
		}
	};

	template <class Iter1, class Iter2>
	bool operator==(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iter1, class Iter2>
	bool operator!=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iter1, class Iter2>
	bool operator<(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class Iter1, class Iter2>
	bool operator<=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iter1, class Iter2>
	bool operator>(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iter1, class Iter2>
	bool operator>=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iter>
	reverse_iterator<Iter>
	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &it)
	{
		return reverse_iterator<Iter>(it.base() - n);
	}

	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type
	operator-(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return rhs.base() - lhs.base();
	}

	template <class Iter>
	reverse_iterator<Iter>
	operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &it)
	{
		return reverse_iterator<Iter>(it.base() + n);
	}

}
#endif