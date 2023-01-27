#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <memory>
#include "Node.hpp"
#include "utility.hpp"
#include <functional>

#include <iostream>
#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b)

namespace ft
{
	template <class Key, class Value, class Compare, class Alloc>
	class avlTree
	{
	public:
		typedef Key key_type;
		typedef Value mapped_type;
		typedef std::size_t size_type;
		typedef ft::Node<key_type, mapped_type> node_type;
		typedef ft::pair<key_type, mapped_type> value_type;
		typedef Alloc allocator;
		typedef node_type *node_pointer;
		typedef Compare compare_type;

		typedef typename allocator::template rebind<node_type>::other node_allocator;
		// typename allocator::template rebind<Node>::other node_allocator;

	protected:
		node_pointer _root;
		node_allocator _alloc;
		compare_type _comp;
		size_type _size;

		node_pointer llRotate(node_pointer parent)
		{
			node_pointer child = parent->left;

			parent->left = child->right;
			if (child->right)
				child->right->parent = parent;

			// if (parent->left)
			// 	parent->left->parent = parent;

			child->right = parent;
			child->parent = parent->parent;
			parent->parent = child;
			return child;
		}

		node_pointer rrRotate(node_pointer parent)
		{
			node_pointer child = parent->right;

			parent->right = child->left;
			if (child->left)
				child->left->parent = parent;

			// if (parent->right)
			// 	parent->right->parent = parent;

			child->left = parent;
			child->parent = parent->parent;
			parent->parent = child;

			return child;
		}

		node_pointer lrRotate(node_pointer parent)
		{

			node_pointer child = parent->left;

			parent->left = rrRotate(child);

			return llRotate(parent);
		}

		node_pointer rlRotate(node_pointer parent)
		{
			node_pointer child = parent->right;

			parent->right = llRotate(child);

			return rrRotate(parent);
		}

		int getHeight(node_pointer p)
		{
			int height = 0;
			if (p != NULL)
			{
				height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
			}
			return height;
		}

		int getBF(node_pointer p)
		{
			if (p == NULL)
			{
				return 0;
			}
			return getHeight(p->left) - getHeight(p->right);
		}

		void deleteDummyNode()
		{
			node_pointer end = end_node();
			end->parent->right = NULL;
			// std::cout << end->parent->content << "\n";
			end->parent = NULL;
			// _alloc.destroy(end);
			_alloc.deallocate(end, 1);
		}

		void insertDummyNode()
		{
			node_pointer dummy = _alloc.allocate(1);
			_alloc.construct(dummy, node_type());

			dummy->content = make_pair(key_type(), mapped_type());
			dummy->left = NULL;
			dummy->right = NULL;
			dummy->parent = end_node();
			dummy->parent->right = dummy;
		}

		node_pointer rebalance(node_pointer node)
		{
			int BF = getBF(node);
			if (BF > 1)
			{
				if (getBF((node)->left) > 0)
					node = llRotate(node);
				else
					node = lrRotate(node);
			}
			else if (BF < -1)
			{
				if (getBF((node)->right) < 0)
				{
					node = rrRotate(node);
				}
				else
				{
					// std::cout << "before rlRR\n";
					node = rlRotate(node);
				}
			}
			else
			{
				// no rebalance
				// std::cout << "no rebalance\n";
			}
			return node;
		}

		void _setParent(node_pointer child, node_pointer parent)
		{
			child->parent = parent;
		}

		node_pointer _insertNode(node_pointer root, value_type content)
		{
			if (root == NULL)
			{
				root = _alloc.allocate(1);
				_alloc.construct(root, node_type());
				root->content = content;
				// root->content(ft::make_pair(content.first, content.second));
				root->left = NULL;
				root->right = NULL;
				root->parent = NULL;
				_size++;
			}
			// else if (content < root->content)
			else if (_comp(content.first, root->content.first))
			{
				root->left = _insertNode(root->left, content);
				_setParent(root->left, root);
				// std::cout << "rebalance parameter root is " << root->content << " when insert content is " << content << "\n";
				root = rebalance(root);
			}
			// else if (content > root->content)
			else if (_comp(root->content.first, content.first))
			{
				root->right = _insertNode(root->right, content);
				_setParent(root->right, root);
				// std::cout << "rebalance parameter root is " << root->content << " when insert content is " << content << "\n";
				root = rebalance(root);
			}
			else
			{
				// printf("이미 같은 키가 있습니다.\n");
				// root->content = content;
			}
			// insertDummyNode();
			return (root);
		}

		node_pointer _findTree(node_pointer root, key_type key) const
		{
			node_pointer p;
			int count = 0;
			p = root;
			while (p != NULL)
			{
				count++;
				// if (content < p->content)
				if (_comp(key, p->content.first))
					p = p->left;
				else if (key == p->content.first) // TODO: comp ????
				{
					// printf("%3d번째에 성공", count);
					return p;
				}
				else
					p = p->right;
			}
			count++;
			return NULL; // 못찾으면 NULL 반환
		}

		void _disPlayInorder(node_pointer root)
		{
			if (root)
			{
				_disPlayInorder(root->left);
				if (root != end_node())
					std::cout << "key_type: " << root->content << "\n";
				_disPlayInorder(root->right);
			}
		}

		void _disPlayInorder_for_debug(node_pointer root)
		{
			if (root)
			{
				_disPlayInorder_for_debug(root->left);
				if (root != _root)
				{
					// std::cout << "^_______^\n";
					std::cout << "key_type: " << root->content;
					if (root->parent)
						std::cout << " and parent is " << root->parent->content << "\n";
					else
						std::cout << "\n";
				}
				else
					std::cout << "key_type: " << root->content << " is real root \n";
				_disPlayInorder_for_debug(root->right);
			}
		}

		// find node that has a value one smaller than the node
		node_pointer _oneSmallerNode(node_pointer node)
		{
			node_pointer res = NULL;
			if (node->left)
			{
				res = node->left;
				while (res->right)
					res = res->right;
			}
			return res;
		}

		// find node that has a value one biger than the node
		node_pointer _oneBigerNode(node_pointer node)
		{
			node_pointer res = NULL;
			if (node->right)
			{
				res = node->right;
				while (res->left)
					res = res->left;
			}
			return res;
		}

		node_pointer _deleteNode(node_pointer root, value_type content)
		{
			if (root == NULL)
				return NULL;

			// if (content < root->content)
			if (_comp(content.first, root->content.first))
			{
				root->left = _deleteNode(root->left, content);
				if (_root)
					root = rebalance(root);
			}
			// else if (content > root->content)
			else if (_comp(root->content.first, content.first))
			{
				root->right = _deleteNode(root->right, content);
				if (_root)
					root = rebalance(root);
			}
			else
			{
				if ((root->left == NULL) && (root->right == NULL)) // no child
				{
					// std::cout << "no child\n";
					// _alloc.deallocate(root, 1);
					root = NULL;
					_size--;
					// std::cout << "you\n";
				}
				else if ((root->left == NULL) || (root->right == NULL)) // one child
				{
					// std::cout << "one child\n";
					node_pointer child = NULL;
					if (root->left)
					{
						child = root->left;
					}
					else
					{
						child = root->right;
					}

					if (root->parent)
					{
						child->parent = root->parent;
						// std::cout << "now child->parent is 2 : " << child->parent->content << "\n";
						if (root->parent->right == root)
						{
							root->parent->right = child;
						}
						else
						{
							root->parent->left = child;
						}
					}
					else
					{
						child->parent = NULL;
					}
					// _alloc.deallocate(root, 1);
					// root = NULL;
					_size--;
					return child;
				}
				else // two child
				{
					// std::cout << "two child\n";
					node_pointer child = NULL;
					node_pointer tmp = root;
					child = _oneSmallerNode(root);
					child->parent = tmp->parent;

					if (tmp->left != child)
					{
						child->left = tmp->left;
						if (tmp->left != NULL)
						{
							tmp->left->parent = child;
						}
					}
					else
					{
						child->left = NULL;
					}

					child->right = tmp->right;
					if (tmp->right != NULL)
					{
						tmp->right->parent = child;
					}
					root = child;
					_alloc.deallocate(tmp, 1);
					_size--;
				}
			}
			return root;
		}

	public:
		/*
		constuctor:
		 */
		// avlTree()
		// {
		// 	_root = NULL;
		// 	_alloc = node_allocator();
		// }

		/*  */
		avlTree(const Compare &comp = Compare(), const Alloc &alloc = Alloc())
		{
			_size = 0;
			_root = NULL;
			_comp = comp;
			_alloc = alloc;
			// _alloc = node_allocator();
		}

		avlTree(value_type content, const Compare &comp = Compare(), const Alloc &alloc = Alloc())
		{
			_size = 0;
			_root = NULL;
			_comp = comp;
			_alloc = alloc;
			// _alloc = node_allocator();
			insertNode(content);
		}

		avlTree(node_pointer n, const Compare &comp = Compare(), const Alloc &alloc = Alloc())
		{
			avlTree(n->content, comp, alloc);
		}

		avlTree(const avlTree &tree)
		{
			*this = tree;
		}

		virtual ~avlTree()
		{
			// TODO: 소멸자 소환하기
		}

		void insertNode(value_type content)
		{
			if (_root)
				deleteDummyNode();
			// std::cout << "sdfsdf\n";
			_root = _insertNode(_root, content);
			insertDummyNode();
		}

		node_pointer findTree(key_type key) const
		{
			return _findTree(_root, key);
		}

		void disPlayInorder()
		{
			_disPlayInorder(_root);
		}

		void deleteNode(value_type content)
		{
			deleteDummyNode();
			_root = _deleteNode(_root, content);
			if (_root)
				insertDummyNode();
		}

		node_pointer begin_node() const
		{
			node_pointer current = _root;
			while (current->left)
				current = current->left;
			return current;
		}

		node_pointer end_node() const
		{
			node_pointer current = _root;
			while (current->right)
			{
				current = current->right;
			}
			return current; // TODO: 원래는 이게 맞음
							// return current->parent;
		}

		size_type size() const
		{
			return _size;
		}

		// avlTree &operator=(const avlTree &tree) // TODO: implement
		// {
		// }

		void disPlayInorder_for_debug()
		{
			_disPlayInorder_for_debug(_root);
		}

		/*
		implement for tree:
		 */
	};
}

#endif