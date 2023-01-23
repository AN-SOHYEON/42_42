#ifndef NODE_HPP
#define NODE_HPP

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
		virtual ~Node() {}
	};

}

#endif