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
			// std::cout << "doing llrotate\n";
			// std::cout << "parent content : " << parent->content << "\n";
			// 4
			node_pointer child = parent->left;
			// std::cout << "child content : " << child->content << "\n";
			// 2
			parent->left = child->right;
			if (parent->left)
				parent->left->parent = parent;
			// std::cout << "parent->left content : " << parent->left->content << "\n";

			child->right = parent;
			parent->parent = child;
			// std::cout << "parent and child->right content : " << parent->content << "\n";
			return child;
		}

		node_pointer rrRotate(node_pointer parent)
		{
			// std::cout << "doing rrrotate\n";
			// std::cout << "parent content : " << parent->content << "\n";
			node_pointer child = parent->right;
			// std::cout << "child content : " << child->content << "\n";

			parent->right = child->left;
			if (parent->right)
				parent->right->parent = parent;
			// std::cout << "parent->right content : " << parent->right->content << "\n";

			child->left = parent;
			parent->parent = child;
			// std::cout << "parent and child->left content : " << parent->content << "\n";

			return child;
		}

		node_pointer lrRotate(node_pointer parent)
		{
			// std::cout << "doing lrrotate\n";
			// std::cout << "parent content : " << parent->content << "\n";

			node_pointer child = parent->left;
			// std::cout << "child content : " << child->content << "\n";

			parent->left = rrRotate(child);
			parent->left->parent = parent;
			// std::cout << "parent->left content : " << parent->left->content << "\n";
			// std::cout << "parent->left->parent content is 4 : " << parent->left->parent->content << "\n";

			return llRotate(parent);
		}

		node_pointer rlRotate(node_pointer parent)
		{
			// disPlayInorder();
			node_pointer child = parent->right;
			parent->right = llRotate(child);
			parent->right->parent = parent;

			// std::cout << "doing rlRR\n";
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

		// node_pointer rebalance(node_pointer *p)
		void rebalance(node_pointer *p)
		{
			int BF = getBF(*p);
			std::cout << "start rebalance----displayInorder--in--debug----\n";
			disPlayInorder_for_debug();
			// _disPlayInorder_for_debug(*p);
			std::cout << "start rebalance----displayInorder--in--debug---fin\n";
			std::cout << "in rebalnce p content is " << (*p)->content << "\n";
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
			std::cout << "in rebalance----displayInorder--in--debug----\n";
			disPlayInorder_for_debug();
			std::cout << "in rebalance----displayInorder--in--debug---fin\n";
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

		node_pointer _deleteNode(node_pointer root, T content)
		{
			std::cout << "hhhhh first root->content : " << root->content << "\n";
			if (root == NULL)
			{
				std::cout << "here\n";
				return NULL;
			}
			node_pointer del = NULL;

			if (root->content < content)
			{
				std::cout << "hhhhh\n";
				std::cout << "_deleteNode parameter root->right->content " << root->right->content << "\n";
				root->right = _deleteNode(root->right, content);
				if (root->right->content)
					std::cout << "return _deleteNode in right : " << root->right->content << " and root content is " << root->content << "\n";
			}
			else if (root->content > content)
			{
				std::cout << "dkdkdkdkdk\n";
				std::cout << "_deleteNode parameter root->left->content " << root->left->content << "\n";
				root->left = _deleteNode(root->left, content);
				if (root->left->content)
					std::cout << "return _deleteNode in left : " << root->left->content << "\n";
			}
			else
			{
				std::cout << "will delete this | root->content : " << root->content << "\n";
				std::cout << "root's parent content : " << root->parent->content << "\n";
				// node_pointer del = NULL;
				if ((root->right == NULL) || (root->left == NULL)) // no child or one child
				{
					if (del == root->left)
						del = root->right;
					else if (del == root->right)
						del = root->left;

					if (del == NULL) // no child
					{
						std::cout << "no child logic\n";
						del = root;
						std::cout << "del's content : " << del->content << "\n";
						std::cout << "del's parent : " << del->parent->content << "\n";
						if (root->parent->left == root)
							root->parent->left = NULL;
						else if (root->parent->right == root)
							root->parent->right = NULL;
						_alloc.deallocate(del, 1);
						del = NULL;
						root = root->parent;
						// std::cout << "==========displayInorder in no child===============\n";
						// disPlayInorder_for_debug();
						// root = NULL;
					}
					else // one child
					{
						root = del;
					}
				}
				else // two child
				{
					std::cout << "here\n";
					del = _oneSmallerNode(root);
					std::cout << "oneSmallerNode : " << del->content << "\n";
					root->content = del->content;
					root->right = _deleteNode(root->right, del->content);
					std::cout << "after _deleteNode in two child : " << root->right->content << "\n";
				}
			}
			if (root == NULL)
			{
				std::cout << "hhhhh ^^^^^^^^^^^^\n";
				return NULL;
			}
			// std::cout << "before rebalance\n";
			rebalance(&root);
			// _alloc.deallocate(del, 1);
			// std::cout << "return value of rebalance is " << res->content << "\n";
			// _disPlayInorder_for_debug(res);
			std::cout << "after rebalance root content is : " << root->content << "\n";
			return root;

			// return rebalance(&root);
			//////////////////////////////////////////////////////////////////////////

			// node_pointer parent, p, succ, succ_parent;
			// node_pointer child;

			// parent = NULL;
			// p = root;
			// while ((p != NULL) && (p->key != x))
			// {
			// 	parent = p;
			// 	if (x < p->key)
			// 		p = p->left;
			// 	else
			// 		p = p->right;
			// }
			// if (p == NULL)
			// {
			// 	// std::cout << "찾는 키는 없음" << std::endl;
			// 	return;
			// }

			// if ((p->left == NULL) && (p->right == NULL))
			// {
			// 	if (parent != NULL)
			// 	{
			// 		if (parent->left == p)
			// 			parent->left = NULL;
			// 		else
			// 			parent->right = NULL;
			// 	}
			// 	else
			// 		root = NULL;
			// }
			// else if ((p->left == NULL) || (p->right == NULL))
			// {
			// 	std::cout << "have one child\n";
			// 	if (p->left != NULL)
			// 		child = p->left;
			// 	else
			// 		child = p->right;

			// 	if (parent != NULL)
			// 	{
			// 		if (parent->left == p)
			// 			parent->left = child;
			// 		else
			// 			parent->right = child;
			// 	}
			// 	else
			// 		root = child;
			// }
			// else
			// {
			// 	succ_parent = p;
			// 	succ = p->left;
			// 	while (succ->right != NULL) // 안들어옴
			// 	{
			// 		succ_parent = succ;
			// 		succ = succ->right;
			// 	}
			// 	if (succ_parent->left == succ)
			// 		succ_parent->left = succ->left;
			// 	else
			// 		succ_parent->right = succ->right;
			// 	p->key = succ->key;
			// 	p = succ;
			// }
			// // // _alloc.destroy(p);
			// // std::cout << "sdf1\n";
			// _alloc.deallocate(p, 1);
			// // free(p);
			// root = rebalance(&root);
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