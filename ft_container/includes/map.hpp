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
	template <
		class Key,
		class T,
		class Compare = std::less<Key>, // map의 정렬 기준 조건자
		class Allocator = std::allocator<ft::pair<const Key, T> > >
	// template <
	// 	class Key,
	// 	class T,
	// 	class Compare,
	// 	class Allocator>
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
		typedef typename allocator_type::template rebind<ft::Node<value_type> >::other node_allocator;
		// typedef typename allocator_type::template rebind<ft::node<value_type> >::other node_allocator;
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
			// map 클래스의 모든 멤버 함수는 value_compare 클래스에 대한 프렌드 접근 권한을 부여받는다.

		protected:
			key_compare comp;

		public:
			value_compare(key_compare c);
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(lhs.first, rhs.first);
			}
		};

	protected:
		tree _tree;
		node_allocator _alloc; // TODO: 둘지말지 고민하기
		key_compare _key_comp;
		value_compare _value_comp;

		template <class InputIterator> // node 기반 컨테이너는 이터레이터간의 거리를 뺄셈으로 구할 수 없다.
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
			_tree;			// TODO: tree 처리
			_alloc = alloc; // TODO: 아ㅏㅏㅏ allocator 모르겠는디ㅣㅣㅣ
			_key_comp = comp;
			_value_comp = value_compare(_key_comp);
		}

		map(const map &other) : _alloc(other._alloc), _key_comp(other._key_comp), _tree(other._tree), _value_comp(other._value_comp) {}

		virtual ~map() {}

		map &operator=(const map &other)
		{
			_tree = other._tree;
			_alloc = other._alloc;
			_key_comp = other._key_comp;
			_value_comp = other._value_comp;
			return (*this);
		}

		allocator_type get_allocator() const
		{
			return _alloc;
		}

		mapped_type &at(const key_type &key)
		{
			if (_tree.findTree(key))
				throw std::out_of_range("map over");
			return _tree.findTree(key)->second; // TODO: 음 pair일 때 어케 find?
		}

		const mapped_type &at(const key_type &key) const
		{
			if (_tree.findTree(key))
				throw std::out_of_range("map over");
			return _tree.findTree(key)->second; // TODO: 음 pair일 때 어케 find?
		}

		T &operator[](const Key &key)
		{
			return _tree.findTree(key)->second;
		}

		/*
		iterator:	TODO: implement
		 */
		iterator begin()
		{
			return iterator(_tree.begin_node());
		}
		const_iterator begin() const
		{
			return const_iterator(_tree.end_node());
		}

		iterator end()
		{
			return iterator(_tree.end_node()); // TODO: iterator
		}
		const_iterator end() const
		{
			return const_iterator(_tree.end_node());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(_tree.end_node());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(_tree.end_node());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_tree.end_node());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(_tree.end_node());
		}

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
			return _distance(begin(), end()); // TODO: distance
		}

		size_type max_size() const
		{
			return alloc.max_size(); // TODO: right?
		}

		/*
		modifiers:
		 */
		// 모든 원소 제거
		void clear();

		ft::pair<iterator, bool> insert(const value_type &value);
		iterator insert(iterator pos, const value_type &value);

		void erase(iterator pos);
		void erase(iterator first, iterator last);
		size_type erase(const Key &key);

		void swap(map &other)
		{
			_swap(_tree, other._tree);
			_swap(_alloc, other._alloc);
			_swap(_key_comp, other._key_comp);
			_swap(_value_comp, other._value_comp);
		}

		/*
		Lookup:
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
		Observers:
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