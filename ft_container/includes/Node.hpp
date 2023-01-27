#ifndef NODE_HPP
#define NODE_HPP

#include <map>

namespace ft
{
	template <typename T>
	struct Node
	{
		T content;
		struct Node *left;
		struct Node *right;
		struct Node *parent;

		Node() {}

		template <typename U>
		Node(const Node<U> &other) : content(other.content), left(other.left), right(other.right), parent(other.parent) {}

		virtual ~Node() {}
	};

	template <class T>
	bool operator==(const Node<T> &lhs, const Node<T> &rhs)
	{
		return (lhs->content == rhs->content);
	}

	template <class T>
	bool operator!=(const Node<T> &lhs, const Node<T> &rhs)
	{
		return (lhs->content != rhs->content);
	}

	template <class T>
	bool operator>(const Node<T> &lhs, const Node<T> &rhs)
	{
		return (lhs->content > rhs->content);
	}

	template <class T>
	bool operator>=(const Node<T> &lhs, const Node<T> &rhs)
	{
		return (lhs->content >= rhs->content);
	}

	template <class T>
	bool operator<=(const Node<T> &lhs, const Node<T> &rhs)
	{
		return (lhs->content <= rhs->content);
	}

	template <class T>
	bool operator<(const Node<T> &lhs, const Node<T> &rhs)
	{
		return (lhs->content < rhs->content);
	}

	template <typename Key, typename Value>
	struct AvlNode
	{
		ft::pair<const Key, Value> content;
		struct AvlNode *left;
		struct AvlNode *right;
		struct AvlNode *parent;

		AvlNode() {}

		template <typename K, typename V>
		AvlNode(const AvlNode<K, V> &other) : content(other.content), left(other.left), right(other.right), parent(other.parent) {}

		virtual ~AvlNode() {}
	};

}

#endif
