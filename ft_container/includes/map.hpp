#ifndef MAP_HPP
#define MAP_HPP

#include "utility.hpp"
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
		class Compare,
		class Allocator>
	class map
	{

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef typename ft::pair<const key_type, mapped_type> value_type;
		typedef typename std::size_t size_type;
		typedef typename std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef typename allocator_type::template rebind<ft::node<value_type> >::other node_allocator;
		// TODO: rebind<ft::avlTree>

		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;

		typedef typename ft::bidirectional_iterator<value_type> iterator;
		typedef typename ft::bidirectional_iterator<const value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

		typedef typename ft::avlTree<value_type> tree;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;

		protected:
			key_compare comp;

		public:
			value_compare(key_compare c);
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(lhs.first, rhs.first);
			}
		};

	private:
		tree *_tree;
		node_allocator _alloc;
		key_compare _key_comp;
		value_compare _value_comp;

	public:
		map()
		{
			_tree = NULL;
			_alloc = node_allocator();
			_key_comp = key_compare();
			_value_comp = value_compare(_key_comp);
		}

		explicit map(const Compare &comp,
					 const Allocator &alloc = Allocator())
		{
			_tree = NULL;
			_alloc = alloc;
			_key_comp = comp;
			_value_comp = value_compare(_key_comp);
		}

		template <class InputIt>
		map(InputIt first, InputIt last,
			const Compare &comp = Compare(),
			const Allocator &alloc = Allocator())
		{

			_alloc = alloc; // TODO: 아ㅏㅏㅏ allocator 모르겠는디ㅣㅣㅣ
			_key_comp = comp;
			_value_comp = value_compare(_key_comp);
		}

		map(const map &other) : _alloc(other._alloc), _key_comp(other._key_comp), _tree(other._tree), _value_comp(other._value_comp) {}

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
		// 모든 원소 제거
		void clear();

		ft::pair<iterator, bool> insert(const value_type &value);
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

		// key의 반복자 구간인 pair 객체
		ft::pair<iterator, iterator> equal_range(const Key &key);
		ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const;

		// key의 시작 구간을 가리키는 반복자
		iterator lower_bound(const Key &key);
		const_iterator lower_bound(const Key &key) const;

		// key의 끝 구간을 가리키는 반복자
		iterator upper_bound(const Key &key);
		const_iterator upper_bound(const Key &key) const;

		/*
		Observers
		 */
		// key 정렬 기준인 조건자를 반환
		key_compare key_comp() const
		{
			return _key_comp;
		}

		// value 정렬 기준인 조건자를 반환
		ft::map::value_compare value_comp() const
		{
			return _value_comp;
		}
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