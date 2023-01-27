#ifndef NODE_HPP
#define NODE_HPP

#include <map>

namespace ft
{
	// template <typename T>
	// struct Node
	// {
	// 	T content;
	// 	struct Node *left;
	// 	struct Node *right;
	// 	struct Node *parent;

	// 	Node() {}

	// 	template <typename U>
	// 	Node(const Node<U> &other) : content(other.content), left(other.left), right(other.right), parent(other.parent) {}

	// 	virtual ~Node() {}
	// };

	template <typename Key, typename Value>
	struct Node
	{
		ft::pair<Key, Value> content;
		struct Node *left;
		struct Node *right;
		struct Node *parent;

		Node() {}

		template <typename K, typename V>
		Node(const Node<K, V> &other) : content(other.content), left(other.left), right(other.right), parent(other.parent) {}

		virtual ~Node() {}
	};

	template <class K, class V>
	bool operator==(const Node<K, V> &lhs, const Node<K, V> &rhs)
	{
		return (lhs->content == rhs->content);
	}

	template <class K, class V>
	bool operator!=(const Node<K, V> &lhs, const Node<K, V> &rhs)
	{
		return (lhs->content != rhs->content);
	}

	template <class K, class V>
	bool operator>(const Node<K, V> &lhs, const Node<K, V> &rhs)
	{
		return (lhs->content > rhs->content);
	}

	template <class K, class V>
	bool operator>=(const Node<K, V> &lhs, const Node<K, V> &rhs)
	{
		return (lhs->content >= rhs->content);
	}

	template <class K, class V>
	bool operator<=(const Node<K, V> &lhs, const Node<K, V> &rhs)
	{
		return (lhs->content <= rhs->content);
	}

	template <class K, class V>
	bool operator<(const Node<K, V> &lhs, const Node<K, V> &rhs)
	{
		return (lhs->content < rhs->content);
	}
}

#endif
