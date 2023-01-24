
#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"
// #include "avlTree.hpp"

#include <iterator>

namespace ft
{
	template <typename T>
	class bidirectional_iterator
	{
	public:
		typedef T iterator_type;
		typedef typename ft::iterator_traits<T *>::value_type value_type;
		typedef std::bidirectional_iterator_tag category_tag;
		typedef typename ft::iterator_traits<T *>::difference_type difference_type;
		typedef typename ft::iterator_traits<T *>::pointer pointer;
		typedef typename ft::iterator_traits<T *>::reference reference;
		typedef typename ft::Node<T> Node;
		// typedef typename ft::Node<T> *Node_pointer;

	private:
		// Node_pointer _node;
		Node *_node;

	public:
		bidirectional_iterator()
		{
			_node = NULL;
		}

		bidirectional_iterator(Node *node) : _node(node) {}

		virtual ~bidirectional_iterator() {}

		template <typename U>
		bidirectional_iterator(const bidirectional_iterator<U> &other) : _node(other._node) {}

		template <typename U>
		bidirectional_iterator &operator=(const bidirectional_iterator<U> &other)
		{
			_node = other._node;
			return *this;
		}

		reference operator*()
		{
			return (this->_node->content);
		}

		pointer operator->() const
		{
			return (&this->_node->content);
		}

		bidirectional_iterator &operator++()
		{
			if (_node->right) // 오른쪽 자식이 있을 떄
			{
				_node = _node->right;
				while (_node->left)
					_node = _node->left;
				return *this;
			}
			while (1)
			{
				if (_node->parent)
				{
					if (_node->parent->left == _node)
					{
						_node = _node->parent;
						break;
					}
					_node = _node->parent;
				}
				else
				{
					throw std::out_of_range("iterator++");
				}
			}
			return *this;
		}

		bidirectional_iterator operator++(int)
		{ // 후위 연산자
			bidirectional_iterator tmp(*this);
			++_node;
			return tmp;
		}

		bidirectional_iterator &operator--()
		{
			if (_node->left) // 오른쪽 자식이 있을 떄
			{
				_node = _node->left;
				while (_node->right)
					_node = _node->right;
				return *this;
			}
			while (1)
			{
				if (_node->parent)
				{
					if (_node->parent->right == _node)
					{
						_node = _node->parent;
						break;
					}
					_node = _node->parent;
				}
				else
				{
					throw std::out_of_range("iterator--");
				}
			}
			return *this;
		}

		bidirectional_iterator operator--(int)
		{ // 후위 연산자
			bidirectional_iterator tmp(*this);
			--_node;
			return tmp;
		}
	};

	template <class Iter1, class Iter2>
	bool operator==(const ft::bidirectional_iterator<Iter1> &lhs, const ft::bidirectional_iterator<Iter2> &rhs)
	{
		return *lhs == *rhs;
	}

	template <class Iter1, class Iter2>
	bool operator!=(const ft::bidirectional_iterator<Iter1> &lhs, const ft::bidirectional_iterator<Iter2> &rhs)
	{
		return *lhs != *rhs;
	}
}

#endif
