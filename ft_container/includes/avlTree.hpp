#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <memory>
#include "Node.hpp"

#include <iostream>
#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b)

namespace ft
{
	// template <typename T>
	template <typename T, typename Key, typename Comp, typename Alloc>
	class avlTree
	{
	public:
		typedef ft::Node<T> Node;
		typedef Alloc allocator;
		typedef Node node_type;
		typedef Node *node_pointer;

		typedef typename allocator::template rebind<Node>::other node_allocator;
		// typename allocator::template rebind<Node>::other node_allocator;

	protected:
		node_pointer _root;
		node_allocator _alloc;

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
			Node *end = end_node();
			end->parent->right = NULL;
			// std::cout << end->parent->content << "\n";
			end->parent = NULL;
			// _alloc.destroy(end);
			_alloc.deallocate(end, 1);
		}

		void insertDummyNode()
		{
			Node *dummy = _alloc.allocate(1);
			dummy->content = NULL;
			dummy->left = NULL;
			dummy->right = NULL;
			dummy->parent = end_node();
			// std::cout << "insertDummyNode current end_node is " << end_node()->content << "\n";
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

		node_pointer _insertNode(node_pointer root, T content)
		{
			if (root == NULL)
			{
				root = _alloc.allocate(1);
				root->content = content;
				root->left = NULL;
				root->right = NULL;
				root->parent = NULL;
			}
			else if (content < root->content)
			{
				root->left = _insertNode(root->left, content);
				_setParent(root->left, root);
				// std::cout << "rebalance parameter root is " << root->content << " when insert content is " << content << "\n";
				root = rebalance(root);
			}
			else if (content > root->content)
			{
				root->right = _insertNode(root->right, content);
				_setParent(root->right, root);
				// std::cout << "rebalance parameter root is " << root->content << " when insert content is " << content << "\n";
				root = rebalance(root);
			}
			else
			{
				// printf("이미 같은 키가 있습니다.\n");
				// exit(1);
				// TODO: logic 필요
			}
			// insertDummyNode();
			return (root);
		}

		node_pointer _findTree(node_pointer root, T content)
		{
			node_pointer p;
			int count = 0;
			p = root;
			while (p != NULL)
			{
				count++;
				if (content < p->content)
					p = p->left;
				else if (content == p->content)
				{
					// printf("%3d번째에 성공", count);
					return p;
				}
				else
					p = p->right;
			}
			count++;
			// printf("%3d번째에 탐색 실패\n", count);
			// std::cout << p->content << "\n";
			return NULL; // 못찾으면 NULL 반환
		}

		void _disPlayInorder(node_pointer root)
		{
			if (root)
			{
				_disPlayInorder(root->left);
				if (root != end_node())
					std::cout << "key: " << root->content << "\n";
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
					std::cout << "key: " << root->content;
					if (root->parent)
						std::cout << " and parent is " << root->parent->content << "\n";
					else
						std::cout << "\n";
				}
				else
					std::cout << "key: " << root->content << " is real root \n";
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

		node_pointer _deleteNode(node_pointer root, T content)
		{
			if (root == NULL)
				return NULL;

			if (content < root->content)
			{
				std::cout << "insert leftline\n";
				root->left = _deleteNode(root->left, content);
				if (_root)
					root = rebalance(root);
			}
			else if (content > root->content)
			{
				std::cout << "insert rightline\n";
				root->right = _deleteNode(root->right, content);
				if (_root)
					root = rebalance(root);
			}
			else
			{
				if ((root->left == NULL) && (root->right == NULL)) // no child
				{
					std::cout << "no child\n";
					// _alloc.deallocate(root, 1);
					root = NULL;
					// std::cout << "you\n";
				}
				else if ((root->left == NULL) || (root->right == NULL)) // one child
				{
					std::cout << "one child\n";
					node_pointer child = NULL;
					if (root->left)
					{
						child = root->left;
					}
					else
					{
						std::cout << "wdf\n";
						child = root->right;
					}

					if (root->parent)
					{
						child->parent = root->parent;
						// std::cout << "now child->parent is 2 : " << child->parent->content << "\n";
						if (root->parent->right == root)
						{
							root->parent->right = child;
							// std::cout << "still root->content is 4 : " << root->content << "\n";
							// std::cout << "change root->parent->right is 3 : " << root->parent->right->content << "\n";
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
					return child;
				}
				else // two child
				{
					std::cout << "two child\n";
					node_pointer child = NULL;
					node_pointer tmp = root;
					// std::cout << "tmp->content : " << tmp->content << "\n";
					// std::cout << "root->content : " << root->content << "\n";
					child = _oneSmallerNode(root);
					// std::cout << "result of oneSmallerNode->content : " << child->content << "\n";
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
				}
			}
			return root;
			//////////////////////////////////////////////////////////////////////////
		}

	public:
		/*
		constuctor:
		 */
		avlTree()
		{
			_root = NULL;
			_alloc = node_allocator();
		}

		/*  */
		avlTree(T content)
		{
			avlTree();
			insertNode(content);
		}

		avlTree(node_pointer n)
		{
			avlTree();
			insertNode(n->content);
		}

		avlTree(const avlTree &tree)
		{
			*this = tree;
		}

		virtual ~avlTree()
		{
			// TODO: 소멸자 소환하기
		}

		void insertNode(T content)
		{
			if (_root)
				deleteDummyNode();
			// std::cout << "sdfsdf\n";
			_root = _insertNode(_root, content);
			insertDummyNode();
		}

		node_pointer findTree(T content)
		{
			return _findTree(_root, content);
		}

		void disPlayInorder()
		{
			_disPlayInorder(_root);
		}

		void deleteNode(T content)
		{
			deleteDummyNode();
			_root = _deleteNode(_root, content);
			// std::cout << "========display in deleteNode()========\n";
			// disPlayInorder();
			if (_root)
				insertDummyNode();
		}

		node_pointer begin_node()
		{
			node_pointer current = _root;
			while (current->left)
				current = current->left;
			return current;
		}

		node_pointer end_node()
		{
			node_pointer current = _root;
			while (current->right)
			{
				current = current->right;
			}
			return current; // TODO: 원래는 이게 맞음
							// return current->parent;
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