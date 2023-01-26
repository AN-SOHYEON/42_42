
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <memory>
// pair
namespace ft
{

	template <bool B, class T = void>
	struct enable_if
	{
	};

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class T>
	struct is_integral
	{
		static const bool value = false;
	};

	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	// since c++11
	// template <>
	// struct is_integral<char16_t>
	// {
	// 	static const bool value = true;
	// };

	// template <>
	// struct is_integral<char32_t>
	// {
	// 	static const bool value = true;
	// };

	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<short>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<long>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<long long>
	{
		static const bool value = true;
	};

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2)) // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	// template <class InputIt1,
	// 		  class InputIt2,
	// 		  class BinaryPredicate>
	// bool equal(InputIt1 first1,
	// 		   InputIt1 last1,
	// 		   InputIt2 first2,
	// 		   BinaryPredicate p)
	// {
	// } TODO: 구현

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <typename _T1, typename _T2>
	struct pair
	{
		typedef _T1 first_value;
		typedef _T2 second_value;

		first_value first;
		second_value second;

		pair(void) : first(), second() {}
		pair(const _T1 &__first, const _T2 &__second) : first(__first), second(__second) {}

		template <class U1, class U2>
		pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}

		pair &operator=(const pair &other)
		{
			first = other.first;
			second = other.second;
			return *this;
		}

		~pair(){};
	};

	template <class T1, class T2>
	bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if ((lhs.first == rhs.first) && (rhs.second == rhs.second))
			return true;
		return false;
	}

	template <class T1, class T2>
	bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if (lhs.first < rhs.first)
			return true;
		if (lhs.first == rhs.first && lhs.second < rhs.second)
			return true;
		return false;
	}

	template <class T1, class T2>
	bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if (lhs.first <= rhs.fist)
			return true;
		return false;
	}

	template <class T1, class T2>
	bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if (lhs.first > rhs.first)
			return true;
		if (lhs.first == rhs.first && lhs.second > rhs.second)
			return true;
		return false;
	}

	template <class T1, class T2>
	bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if (lhs.first >= rhs.fist)
			return true;
		return false;
	}

	template <typename _T1, typename _T2>
	pair<_T1, _T2> make_pair(_T1 first, _T2 second)
	{
		return pair<_T1, _T2>(first, second);
	}

	template <typename U>
	struct Less : public std::binary_function<U, U, bool>
	{
		bool operator()(const U &left, const U &right) const
		{
			return left < right;
		}
	};

}

#endif
