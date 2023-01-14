#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include "random_access_iterator.hpp"

#include <vector>

namespace ft
{

	template <typename T, typename Allocator = std::allocator<T>>
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
		typedef typename iterator_traits<iterator>::difference_type difference_type;

	private:
		pointer arr;
		size_type size;
		size_type capacity;
		allocator_type alloc;

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
			size = 0;
			capacity = 0;
			alloc = allocator_type();
		}

		explicit vector(const Allocator &alloc)
		{
			arr = NULL;
			size = 0;
			capacity = 0;
			this->alloc = alloc;
		}

		explicit vector(size_type count,
						const T &value = T(),
						const Allocator &alloc = Allocator())
		{
			size = count;
			capacity = count;
			this->alloc = alloc;
			arr = alloc.allocate(capacity);
			for (size_type i = 0; i < size; i++)
				arr[i] = value[i];
		}

		template <class InputIt>
		vector(InputIt first, InputIt last,
			   const Allocator &alloc = Allocator())
		{
			arr = NULL;
			size = 0;
			capacity = 0;
			this->alloc = alloc;
			assign(first, last);
		}

		vector(const vector &other)
		{
			*this = other;
		}

		vector &operator=(const vector &other)
		{
			this->alloc = other.alloc;
			assign(other.begin(), other.end());
			return (*this);
		}

		virtual ~vector()
		{
			for (size_type i = 0; i < capacity; i++)
			{
				alloc.destroy(&arr[i]);
			}
			alloc.deallocate(arr, capacity);
		}

		void reserve(size_type new_cap)
		{
			if (new_cap > capacity)
			{
				pointer tmp;
				tmp = alloc.allocate(new_cap);
				for (size_type i = 0; i < size; i++)
					tmp[i] = arr[i];
				for (size_type i = 0; i < capacity; i++)
				{
					alloc.destroy(&arr[i]);
				}
				if (arr)
					alloc.deallocate(arr, capacity);
				arr = tmp;
				capacity = new_cap;
				size = new_cap;
			}
		}

		void push_back(const T &value)
		{
			if (size == capacity)
			{
				if (capacity)
					reserve(capacity * 2);
				else
					reserve(1 * 2);
			}
			arr[size] = value;
			size++;
		}

		void pop_back()
		{
			if (size > 0)
			{
				alloc.destroy(&arr[size]);
				size--;
			}
		}

		void clear()
		{
			for (size_type i = 0; i < capacity; i++)
			{
				alloc.destroy(&arr[i]);
			}
			size = 0;
		}

		void assign(size_type count, const T &value)
		{
			clear();
			reserve(count);
			for (size_type i = 0; i < count; i++)
			{
				push_back(value);
			}
			size = count;
		}

		template <class InputIt>
		void assign(InputIt first, InputIt last)
		{
			typedef typename iterator_trais<InputIt>::size_type inputit_size_type;

			clear();
			inputit_size_type count = last - first;
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
			return iterator(&arr[size]);
		}

		const_iterator end() const
		{
			return const_iterator(&arr[size]);
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
			if (size == capacity)
			{
				if (capacity)
					reserve(capacity * 2);
				else
					reserve(1 * 2);
			}
			size_type index = pos - begin();
			if (index <= size)
			{
				for (size_type i = size; i > index; i--)
					arr[i + 1] = arr[i];
			}
			arr[index] = value;
			size++;
		}

		iterator insert(const_iterator pos, size_type count, const T &value)
		{
			if (size + count >= capacity)
			{
				if (capacity)
					reserve(capacity * 2);
				else
					reserve(1 * 2);
			}
			size_type index = pos - begin();
			if (index <= size)
			{
				for (size_type i = size; i > index; i--)
					arr[i + 1] = arr[i];
			}
			for (size_type i = 0; i < count; i++)
				arr[index + i] = value;
			size = size + count;
		}

		template <class InputIt>
		iterator insert(const_iterator pos, InputIt first, InputIt last)
		{
			typedef typename iterator_traits<InputIt>::size_type inputit_size;
			inputit_size count = last - first;
			if (size + count >= capacity)
			{
				if (capacity)
					reserve(capacity * 2);
				else
					reserve(1 * 2);
			}
			size_type index = pos - begin();
			if (index <= size)
			{
				for (size_type i = size; i > index; i--)
					arr[i + 1] = arr[i];
			}
			for (size_type i = 0; i < count; i++)
				arr[index + i] = *(first + i);
			size = size + count;
		}

		void resize(size_type count, T value = T())
		{
			if (size >= count)
			{
				for (size_type i = count + 1; i < size; i++)
					alloc.destroy(&arr[i]);
			}
			else
			{
				if (capacity <= count)
				{
					if (capacity)
						reserve(capacity * 2);
					else
						reserve(1 * 2);
					for (size_type i = size + 1; i < count; i++)
						arr[i] = value;
				}
			}
			size = count;
		}

		bool empty() const
		{
			if (arr && size > 0)
				return true;
			return false;
		}

		iterator erase(iterator pos)
		{
			if (!empty)
			{
				size_type index = pos - begin();
				alloc.destroy(&arr[index]);
				if (index < size)
				{
					for (size_type i = index; i < size; i++)
						arr[i] = arr[i + 1];
				}
				size--;
			}
		}

		iterator erase(iterator first, iterator last)
		{
			if (!empty)
			{
				size_type f = first - begin();
				size_type l = last - begin();
				for (size_type i = f; i < l; i++)
				{
					alloc.destroy(&arr[i]);
					// size--;
				}
				if (l < size)
				{
					for (size_type i = f; i < size; i++)
						arr[i] = arr[i + (l - f)];
				}
				size = size - (l - f);
			}
		}

		void swap(vector &other)
		{
			_swap(this->alloc, other.alloc);
			_swap(this->size, other.size);
			_swap(this->capacity, other.capacity);
			_swap(this->arr, other.arr);
		}

		reference at(size_type pos)
		{
			return &arr[pos];
		}

		const_reference at(size_type pos) const
		{
			return &arr[pos];
		}

		reference operator[](size_type pos)
		{
			return &arr[pos];
		}

		const_reference operator[](size_type pos) const
		{
			return &arr[pos];
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
			return arr[size - 1];
		}

		const_reference back() const
		{
			return arr[size - 1];
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
			return size;
		}

		size_type max_size() const
		{
			return alloc.max_size();
		}

		size_type capacity() const
		{
			return capacity;
		}
	};

	// template <class T, class Alloc>
	// bool operator==(const std::vector<T, Alloc> &lhs,
	// 				const std::vector<T, Alloc> &rhs);

	// template <class T, class Alloc>
	// bool operator!=(const std::vector<T, Alloc> &lhs,
	// 				const std::vector<T, Alloc> &rhs);

	// template <class T, class Alloc>
	// bool operator<(const std::vector<T, Alloc> &lhs,
	// 			   const std::vector<T, Alloc> &rhs);

	// template <class T, class Alloc>
	// bool operator<=(const std::vector<T, Alloc> &lhs,
	// 				const std::vector<T, Alloc> &rhs);

	// template <class T, class Alloc>
	// bool operator>(const std::vector<T, Alloc> &lhs,
	// 			   const std::vector<T, Alloc> &rhs);

	// template <class T, class Alloc>
	// bool operator>=(const std::vector<T, Alloc> &lhs,
	// 				const std::vector<T, Alloc> &rhs);

	// template <class T, class Alloc>
	// void swap(std::vector<T, Alloc> &lhs,
	// 		  std::vector<T, Alloc> &rhs);

}

#endif