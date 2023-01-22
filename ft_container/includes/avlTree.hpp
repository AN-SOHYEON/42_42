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
		typedef ft::node<T> Node;
		// typedef std::allocator<Node> allocator_node;
		typedef Alloc allocator;
		// typedef typename allocator::template rebind<Node>::other node_allocator;
		typedef Node node_type;
		typedef Node *node_pointer;

		typedef typename allocator::template rebind<Node>::other node_allocator;

	protected:
		node_pointer _root;
		node_allocator _alloc;

		node_pointer llRotate(node_pointer parent)
		{
			node_pointer child = parent->left;
			parent->left = child->right;
			child->right = parent;
			return child;
		}

		node_pointer rrRotate(node_pointer parent)
		{
			node_pointer child = parent->right;
			parent->right = child->left;
			child->left = parent;
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

		node_pointer rebalance(node_pointer *p)
		{
			int BF = getBF(*p);

			if (BF > 1)
			{
				if (getBF((*p)->left) > 0)
					*p = llRotate(*p);
				else
					*p = lrRotate(*p);
			}
			else if (BF < -1)
			{
				if (getBF((*p)->right) < 0)
				{
					*p = rrRotate(*p);
				}
				else
				{
					*p = rlRotate(*p);
				}
			}
			return *p;
		}

		node_pointer _insertNode(node_pointer *root, T x)
		{
			if (*root == NULL)
			{
				*root = _alloc.allocate(1);
				(*root)->key = x;
				(*root)->left = NULL;
				(*root)->right = NULL;
			}
			else if (x < (*root)->key)
			{
				(*root)->left = _insertNode(&((*root)->left), x);
				(*root) = rebalance(root);
			}
			else if (x > (*root)->key)
			{
				(*root)->right = _insertNode(&((*root)->right), x);
				(*root) = rebalance(root);
			}
			else
			{
				// printf("이미 같은 키가 있습니다.\n");
				// exit(1);
				// TODO: logic 필요
			}
			return (*root);
		}

		node_pointer _findTree(node_pointer root, T x)
		{
			node_pointer p;
			int count = 0;
			p = root;
			while (p != NULL)
			{
				count++;
				if (x < p->key)
					p = p->left;
				else if (x == p->key)
				{
					// printf("%3d번째에 성공", count);
					return p;
				}
				else
					p = p->right;
			}
			count++;
			// printf("%3d번째에 탐색 실패\n", count);
			// std::cout << p->key << "\n";
			return NULL; // 못찾으면 NULL 반환
		}

		void _disPlayInorder(node_pointer root)
		{
			if (root)
			{
				_disPlayInorder(root->left);
				std::cout << "key: " << root->key << " " << std::endl;
				_disPlayInorder(root->right);
			}
		}

		void _deleteNode(node_pointer root, T x)
		{
			node_pointer parent, p, succ, succ_parent;
			node_pointer child;

			parent = NULL;
			p = root;
			while ((p != NULL) && (p->key != x))
			{
				parent = p;
				if (x < p->key)
					p = p->left;
				else
					p = p->right;
			}
			if (p == NULL)
			{
				// std::cout << "찾는 키는 없음" << std::endl;
				return;
			}

			if ((p->left == NULL) && (p->right == NULL))
			{
				if (parent != NULL)
				{
					if (parent->left == p)
						parent->left = NULL;
					else
						parent->right = NULL;
				}
				else
					root = NULL;
			}
			else if ((p->left == NULL) || (p->right == NULL))
			{
				std::cout << "have one child\n";
				if (p->left != NULL)
					child = p->left;
				else
					child = p->right;

				if (parent != NULL)
				{
					if (parent->left == p)
						parent->left = child;
					else
						parent->right = child;
				}
				else
					root = child;
			}
			else
			{
				succ_parent = p;
				succ = p->left;
				while (succ->right != NULL) // 안들어옴
				{
					succ_parent = succ;
					succ = succ->right;
				}
				if (succ_parent->left == succ)
					succ_parent->left = succ->left;
				else
					succ_parent->right = succ->right;
				p->key = succ->key;
				p = succ;
			}
			// // _alloc.destroy(p);
			// std::cout << "sdf1\n";
			_alloc.deallocate(p, 1);
			// free(p);
			root = rebalance(&root);
		}

	public:
		avlTree()
		{
			_root = NULL;
			_alloc = node_allocator();
		}

		virtual ~avlTree()
		{
			// TODO: 소멸자 소환하기
		}

		void insertNode(T key)
		{
			_insertNode(&_root, key);
		}

		void findTree(T x)
		{
			_findTree(_root, x);
		}

		void disPlayInorder()
		{
			_disPlayInorder(_root);
		}

		void deleteNode(T key)
		{
			_deleteNode(_root, key);
		}
	};
}

#endif