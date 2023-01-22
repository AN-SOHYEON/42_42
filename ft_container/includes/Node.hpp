#ifndef NODE_HPP
#define NODE_HPP

namespace ft
{
	template <typename T>
	struct node
	{
		T key;
		struct node *left;
		struct node *right;

		node() {}
		virtual ~node() {}
	};

}

#endif