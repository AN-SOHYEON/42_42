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

		void rebalance(node_pointer *p)
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
					// std::cout << "before rlRR\n";
					*p = rlRotate(*p);
				}
			}
			else
			{
				// no rebalance
				std::cout << "no rebalance\n";
			}
			// insertDummyNode();
			// std::cout << "in rebalance----displayInorder--in--debug----\n";
			// disPlayInorder_for_debug();
			// std::cout << "in rebalance----displayInorder--in--debug---fin\n";
			// return *p;
		}

		void _setParent(node_pointer *child, node_pointer parent)
		{
			(*child)->parent = parent;
		}

		node_pointer _insertNode(node_pointer *root, T content)
		{
			if (*root == NULL)
			{
				*root = _alloc.allocate(1);
				(*root)->content = content;
				(*root)->left = NULL;
				(*root)->right = NULL;
				(*root)->parent = NULL;
			}
			else if (content < (*root)->content)
			{
				// deleteDummyNode();
				(*root)->left = _insertNode(&((*root)->left), content);
				_setParent(&((*root)->left), (*root));
				// std::cout << "after _setParent : " << (*root)->left->parent->content << " is " << (*root)->left->content << " 's parent\n";
				std::cout << "rebalance parameter root is " << (*root)->content << " when insert content is " << content << "\n";
				// (*root) = rebalance(root);
				rebalance(root);
				// if ((*root)->parent)
				// {
				// 	std::cout << "now parent of root(" << (*root)->content << ") is " << (*root)->parent->content << "\n";
				// 	std::cout << "now parent of rootchild(" << (*root)->right->content << ") is " << (*root)->right->parent->content << "\n";
				// }
			}
			else if (content > (*root)->content)
			{
				// deleteDummyNode();
				(*root)->right = _insertNode(&((*root)->right), content);
				_setParent(&((*root)->right), (*root));
				// std::cout << "after _setParent : " << (*root)->right->parent->content << " is " << (*root)->right->content << " 's parent\n";
				std::cout << "rebalance parameter root is " << (*root)->content << " when insert content is " << content << "\n";
				// (*root) = rebalance(root);
				rebalance(root);
				// if ((*root)->parent)
				// {
				// 	std::cout << "now parent of root(" << (*root)->content << ") is " << (*root)->parent->content << "\n";
				// 	std::cout << "now parent of rootchild(" << (*root)->right->content << ") is " << (*root)->right->parent->content << "\n";
				// }
			}
			else
			{
				// printf("이미 같은 키가 있습니다.\n");
				// exit(1);
				// TODO: logic 필요
			}
			// insertDummyNode();
			return (*root);
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
					std::cout << "key: " << root->content << " " << std::endl;
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

		void _deleteNode(node_pointer root, T content)
		{
			(void)root;
			node_pointer del = _findTree(_root, content);
			if (del == NULL) // content가 존재하지 않음
				return;

			if ((del->left == NULL) && (del->right == NULL)) // no child
			{
				_alloc.deallocate(del, 1);
				del = NULL;
			}
			else if ((del->left == NULL) || (del->right == NULL)) // one child
			{
				node_pointer child = NULL;
				if (del->left)
				{
					child = del->left;
				}
				else
				{
					child = del->right;
				}
				child->parent = del->parent;
				_alloc.deallocate(del, 1);
				del = NULL;
			}
			else // two child
			{
				node_pointer child = NULL;
				node_pointer tmp = del;

				child = _oneSmallerNode(del);
				std::cout << "result of oneSmallerNode->content : " << child->content << "\n";
				child->parent = del->parent;
				child->left = del->left;
				if (tmp->left != NULL)
				{
					tmp->left->parent = child;
				}
				child->right = tmp->right;
				if (tmp->right != NULL)
				{
					tmp->right->parent = child;
				}
				del = child;
				_alloc.deallocate(tmp, 1);
			}
			rebalance(&_root);
			std::cout << "here\n";
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
			// _insertNode(&_root, content);
			// insertDummyNode();
		}

		avlTree(node_pointer n)
		{
			avlTree();
			insertNode(n->content);
			// _insertNode(&_root, n->content);
			// insertDummyNode();
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
			_insertNode(&_root, content);
			// std::cout << "werwer\n";
			insertDummyNode();
		}

		void findTree(T content)
		{
			_findTree(_root, content);
		}

		void disPlayInorder()
		{
			_disPlayInorder(_root);
		}

		void deleteNode(T content)
		{
			deleteDummyNode();
			_deleteNode(_root, content);
			insertDummyNode();
		}

		Node *begin_node()
		{
			Node *current = _root;
			while (current->left)
				current = current->left;
			return current;
		}

		Node *end_node()
		{
			Node *current = _root;
			while (current->right)
				current = current->right;
			return current; // TODO: 원래는 이게 맞음
							// return current->parent;
		}

		avlTree &operator=(const avlTree &tree) // TODO: implement
		{
		}

		void disPlayInorder_for_debug()
		{
			_disPlayInorder_for_debug(_root);
		}
	};
}

#endif