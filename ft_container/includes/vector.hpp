#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "random_access_iterator.hpp"
#include "utility.hpp"

#include <vector>

namespace ft
{

	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{

	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::random_access_iterator<T> iterator;
		typedef ft::random_access_iterator<const T> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	protected:
		pointer arr;
		size_type _size;
		size_type _capacity;
		allocator_type alloc;

		// TODO: 이거...>쓸수 밖에 없느데..... InputIterator에 노드기반 이터레이터들어오면 뺄셈으로는 차이를 구할수가 없음....
		// 아니면 이터레이터별로 protected 멤버함수로 가지도록 할수도?
		template <class InputIterator>
		typename iterator_traits<InputIterator>::difference_type _distance(InputIterator first, InputIterator last)
		{
			typename iterator_traits<InputIterator>::difference_type n = 0;
			while (first != last)
			{
				first++;
				n++;
			}
			return (n);
		}

		template <typename U>
		void _swap(U &a, U &b)
		{
			U tmp = a;
			a = b;
			b = tmp;
		}

	public:
		// (constructor)
		vector()
		{
			arr = NULL;
			_size = 0;
			_capacity = 0;
			alloc = allocator_type();
		}

		explicit vector(const Allocator &alloc)
		{
			arr = NULL;
			_size = 0;
			_capacity = 0;
			this->alloc = alloc;
		}

		explicit vector(size_type count,
						const T &value = T(),
						const Allocator &alloc = Allocator())
		{
			_size = count;
			_capacity = count;
			this->alloc = alloc;
			arr = this->alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				arr[i] = value;
		}

		template <class InputIt>
		vector(InputIt first, InputIt last,
			   const Allocator &alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = NULL)
		{
			arr = NULL;
			_size = 0;
			_capacity = 0;
			this->alloc = alloc;
			assign(first, last);
		}

		vector(const vector &other)
		{
			*this = other;
		}

		vector &operator=(const vector &other)
		{
			this->_capacity = 0;
			this->_size = 0;
			this->arr = NULL;
			this->alloc = other.alloc;
			assign(other.begin(), other.end());
			return (*this);
		}

		virtual ~vector()
		{
			for (size_type i = 0; i < _size; i++)
			{
				alloc.destroy(&arr[i]);
			}
			alloc.deallocate(arr, _capacity);
		}

		void reserve(size_type new_cap)
		{
			if (new_cap > _capacity)
			{
				pointer tmp;
				tmp = this->alloc.allocate(new_cap);
				for (size_type i = 0; i < _size; i++)
					tmp[i] = arr[i];
				for (size_type i = 0; i < _size; i++)
				{
					alloc.destroy(&arr[i]);
				}
				if (arr)
					alloc.deallocate(arr, _capacity);
				arr = tmp;
				_capacity = new_cap;
			}
		}

		void push_back(const T &value)
		{
			if (_size == _capacity)
			{
				if (_capacity)
					reserve(_capacity * 2);
				else
					reserve(1 * 2);
			}
			arr[_size] = value; // 왜 -1 안해야되는지 고민할것 -> 왜냐면 현재 마지막칸([size-1]) 다음에 원소를 넣어야 하니까ㅏ
			_size++;
		}

		void pop_back()
		{
			if (_size > 0)
			{
				alloc.destroy(&arr[_size - 1]);
				_size--;
			}
		}

		void clear()
		{
			for (size_type i = 0; i < _capacity; i++)
			{
				alloc.destroy(&arr[i]);
			}
			_size = 0;
		}

		void assign(size_type count, const T &value)
		{
			clear();
			reserve(count);
			for (size_type i = 0; i < count; i++)
			{
				push_back(value);
			}
			_size = count;
		}

		template <class InputIt>
		void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = NULL)
		{
			typedef typename iterator_traits<InputIt>::difference_type inputit_size_type;
			clear();
			inputit_size_type count = _distance(first, last); // last - first;

			reserve(count);
			for (InputIt it = first; it != last; it++)
			{
				push_back(*it);
			}
		}

		iterator begin()
		{
			return iterator(arr);
		}

		const_iterator begin() const
		{
			return const_iterator(arr);
		}

		iterator end()
		{
			return iterator(&arr[_size]);
		}

		const_iterator end() const
		{
			return const_iterator(&arr[_size]);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		iterator insert(const_iterator pos, const T &value)
		{
			size_type index = pos - begin();
			if (_size == _capacity)
			{
				if (_capacity)
					reserve(_capacity * 2);
				else
					reserve(1 * 2);
			}
			if (index < _size)
			{
				for (size_type i = _size; i > index; i--)
					arr[i] = arr[i - 1]; // TODO: arr[i + 1] = arr [i] 이랑 뭐가 다르지? 이건 왜안됨!??????!?!?!?
			}
			arr[index] = value;
			_size++;
			return iterator(&arr[index]);
		}

		iterator insert(const_iterator pos, size_type count, const T &value)
		{
			size_type index = pos - begin();
			if (_size + count > _capacity)
			{
				// if (_capacity)
				reserve(_size + count);
				// else
				// reserve(1 * 2);
			}
			if (index < _size)
			{
				for (size_type i = _size + count - 1; i >= index + count; i--)
				{
					arr[i] = arr[i - count];
				}
			}
			for (size_type i = 0; i < count; i++)
				arr[index + i] = value;
			_size = _size + count;
			return iterator(&arr[index]);
		}

		template <class InputIt>
		iterator insert(const_iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = NULL)
		{
			// std::cout << "bbb " << pos - this->begin() << std::endl;
			typedef typename iterator_traits<InputIt>::difference_type inputit_size;

			size_type index = pos - begin();
			inputit_size count = _distance(first, last); // last - first;
			if (_size + count > _capacity)
			{
				reserve(_size + count);

				// if (_capacity)
				// {
				// 	// std::cout << "cccc " << pos - this->begin() << std::endl;
				// 	reserve(_capacity * 2);
				// }
				// else
				// 	reserve(1 * 2);
			}
			if (index < _size) // TODO: = 이 들어가야 하는가?
			{
				for (size_type i = _size + count - 1; i >= index + count; i--) // TODO: = 이 들어가야 하는기?  i >= index + count
					arr[i] = arr[i - count];
			}
			for (inputit_size i = 0; i < count; i++)
			{
				arr[index + i] = *(first++);
			}

			_size = _size + count;
			return iterator(&arr[index]);
		}

		void resize(size_type count, T value = T())
		{
			if (_size > count)
			{
				for (size_type i = count; i < _size; i++)
					alloc.destroy(&arr[i]);
			}
			else
			{
				if (_capacity <= count)
				{
					// if (_capacity)
					reserve(count);
					// else
					// 	reserve(1 * 2);
				}
				for (size_type i = _size; i < count; i++)
					arr[i] = value;
			}
			_size = count;
		}

		bool empty() const
		{
			if (arr && _size > 0)
				return false;
			return true;
		}

		iterator erase(iterator pos)
		{
			size_type index = pos - begin();
			if (!empty())
			{
				alloc.destroy(&arr[index]);
				if (index < _size)
				{
					for (size_type i = index; i < _size; i++)
						arr[i] = arr[i + 1];
				}
				_size--;
			}
			return iterator(&arr[index]);
		}

		iterator erase(iterator first, iterator last)
		{
			size_type f = first - begin();
			size_type l = last - begin();
			if (!empty())
			{
				for (size_type i = f; i < l; i++)
				{
					alloc.destroy(&arr[i]);
					// _size--;
				}
				if (l < _size)
				{
					for (size_type i = f; i < _size; i++)
						arr[i] = arr[i + (l - f)];
				}
				_size = _size - (l - f);
			}
			return iterator(&arr[f]);
		}

		void swap(vector &other)
		{
			_swap(this->alloc, other.alloc);
			_swap(this->_size, other._size);
			_swap(this->_capacity, other._capacity);
			_swap(this->arr, other.arr);
		}

		reference at(size_type pos)
		{
			if (pos > _size)
				throw std::out_of_range("vector");
			return arr[pos];
		}

		const_reference at(size_type pos) const
		{
			if (pos > _size)
				throw std::out_of_range("vector");
			return arr[pos];
		}

		reference operator[](size_type pos)
		{
			return arr[pos];
		}

		const_reference operator[](size_type pos) const
		{
			return arr[pos];
		}

		reference front()
		{
			return arr[0];
		}

		const_reference front() const
		{
			return arr[0];
		}

		reference back()
		{
			return arr[_size - 1];
		}

		const_reference back() const
		{
			return arr[_size - 1];
		}

		T *data()
		{
			return arr;
		}

		const T *data() const
		{
			return arr;
		}

		size_type size() const
		{
			return _size;
		}

		size_type max_size() const
		{
			return alloc.max_size();
		}

		size_type capacity() const
		{
			return _capacity;
		}
	};

	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> &lhs,
					const ft::vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		ft::random_access_iterator<const T> it_lhs = lhs.begin();
		ft::random_access_iterator<const T> it_rhs = rhs.begin();
		while (it_lhs != lhs.end())
		{
			if (*it_lhs != *it_rhs)
				return false;
			it_lhs++;
			it_rhs++;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &lhs,
					const ft::vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return true;
		ft::random_access_iterator<const T> it_lhs = lhs.begin();
		ft::random_access_iterator<const T> it_rhs = rhs.begin();
		while (it_lhs != lhs.end())
		{
			if (*it_lhs != *it_rhs)
				return true;
			it_lhs++;
			it_rhs++;
		}
		return false;
	}

	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> &lhs,
				   const ft::vector<T, Alloc> &rhs)
	{
		if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> &lhs,
					const ft::vector<T, Alloc> &rhs)
	{
		if (lhs == rhs)
			return true;
		if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> &lhs,
				   const ft::vector<T, Alloc> &rhs)
	{
		if (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()))
			return true;
		return false;
	}
	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> &lhs,
					const ft::vector<T, Alloc> &rhs)
	{
		if (lhs == rhs)
			return true;
		if (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()))
			return true;
		return false;
	}

	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc> &lhs,
			  ft::vector<T, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}

}

#endif