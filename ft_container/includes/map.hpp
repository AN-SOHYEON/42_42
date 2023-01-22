#ifndef MAP_HPP
#define MAP_HPP

// #include "../includes/utility.hpp"
#include <utility>

#include <functional> // std::less
#include <memory>
#include "avlTree.hpp"
#include "bidirectional_iterator.hpp"

#include <map>

namespace ft
{
	// template <
	// 	class Key,
	// 	class T,
	// 	class Compare = std::less<Key>, // map의 정렬 기준 조건자
	// 	class Allocator = std::allocator<ft::pair<const Key, T> > >
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> > >
	class map
	{

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef typename std::pair<const key_type, mapped_type> value_type;
		typedef typename std::size_t size_type;
		typedef typename std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;

		typedef typename ft::bidirectional_iterator<value_type> iterator;
		typedef typename ft::bidirectional_iterator<const value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

		typedef typename ft::avlTree<value_type> tree;

	private:
		tree *_tree;
		allocator_type _alloc;
		key_compare _comp;

	public:
		class value_compare; // TODO: implement

		map() {}

		explicit map(const Compare &comp,
					 const Allocator &alloc = Allocator())
		{
			_tree = NULL;
			_alloc = alloc;
			_comp = comp;
		}

		template <class InputIt>
		map(InputIt first, InputIt last,
			const Compare &comp = Compare(),
			const Allocator &alloc = Allocator())
		{

			_alloc = alloc;
			_comp = comp;
		}
		map(const map &other) : _alloc(other._alloc), _comp(other._comp), _tree(other._tree) {}

		virtual ~map() {}

		map &operator=(const map &other);

		allocator_type get_allocator() const
		{
			return _alloc;
		}

		mapped_type &at(const key_type &key)
		{
			if (_tree->findTree(key))
				throw std::out_of_range("map");
			return _tree->findTree(key)->second; // TODO: 음 pair일 때 어케 find?
		}

		const mapped_type &at(const key_type &key) const
		{
			if (_tree->findTree(key))
				throw std::out_of_range("map");
			return _tree->findTree(key)->second; // TODO: 음 pair일 때 어케 find?
		}

		T &operator[](const Key &key);

		/*
		iterator:	TODO: implement
		 */
		iterator begin()
		{
			// return iterator()
		}
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/*
		capacity:
		 */
		bool empty() const
		{
			if (begin() == end())
				return true;
			return false;
		}

		size_type size() const
		{
			return std::distance(begin(), end()); // TODO: distance
		}

		size_type max_size() const
		{
			return alloc.max_size(); // TODO: right?
		}

		/*
		modifiers
		 */
		void clear();
		std::pair<iterator, bool> insert(const value_type &value);
		iterator insert(iterator pos, const value_type &value);

		void erase(iterator pos);
		void erase(iterator first, iterator last);
		size_type erase(const Key &key);

		void swap(map &other);

		/*
		Lookup
		 */
		size_type count(const Key &key) const;

		iterator find(const Key &key);
		const_iterator find(const Key &key) const;

		std::pair<iterator, iterator> equal_range(const Key &key);
		std::pair<const_iterator, const_iterator> equal_range(const Key &key) const;

		iterator lower_bound(const Key &key);
		const_iterator lower_bound(const Key &key) const;

		iterator upper_bound(const Key &key);
		const_iterator upper_bound(const Key &key) const;

		/*
		Observers
		 */
		key_compare key_comp() const;

		std::map::value_compare value_comp() const;
	};

	/* non member function */
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const std::map<Key, T, Compare, Alloc> &lhs,
					const std::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const std::map<Key, T, Compare, Alloc> &lhs,
					const std::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const std::map<Key, T, Compare, Alloc> &lhs,
				   const std::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const std::map<Key, T, Compare, Alloc> &lhs,
					const std::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const std::map<Key, T, Compare, Alloc> &lhs,
				   const std::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const std::map<Key, T, Compare, Alloc> &lhs,
					const std::map<Key, T, Compare, Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	void swap(std::map<Key, T, Compare, Alloc> &lhs,
			  std::map<Key, T, Compare, Alloc> &rhs);

}

#endif