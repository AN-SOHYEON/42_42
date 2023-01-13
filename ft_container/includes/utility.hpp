
#ifndef UTILITY_HPP
# define UTILITY_HPP

// pair
namespace ft {

template<typename _T1, typename _T2>
struct pair {
	typedef _T1 first;
	typedef _T2 second;

	pair(void):first(), second() {}
	pair(const T1& __first, const T2& __second):first(__first), second(__second) {}
};

template<typename _T1, typename _T2>
pair<_T1, _T2> make_pair(_T1 first, _T2 second) {
	return pair<_T1, _T2>(first, second);
}

}





#endif
// - std::enable_if
// 	: SFINAE
// - std::is_integral
// - std::equal and/or std::lexicographical_compare
// - std::pair
// - std::make_pair