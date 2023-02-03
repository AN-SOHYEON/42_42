#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <stdio.h>

#include <functional>
#include <iostream>
#include <memory>

#include "Node.hpp"
#include "utility.hpp"

#define MAX(a, b) ((a > b) ? a : b)

namespace ft {
template <class Key, class Value, class Compare, class Alloc>
class avlTree {
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
    typedef typename node_allocator::pointer pointer;
    typedef typename node_allocator::const_pointer const_pointer;
    // typename allocator::template rebind<Node>::other node_allocator;

  protected:
    node_pointer _root;
    node_allocator _alloc;
    compare_type _comp;
    size_type _size;
    node_pointer _dummy;

    node_pointer llRotate(node_pointer parent) {
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

    node_pointer rrRotate(node_pointer parent) {
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

    node_pointer lrRotate(node_pointer parent) {
        node_pointer child = parent->left;

        parent->left = rrRotate(child);

        return llRotate(parent);
    }

    node_pointer rlRotate(node_pointer parent) {
        node_pointer child = parent->right;

        parent->right = llRotate(child);

        return rrRotate(parent);
    }

    int getHeight(node_pointer p) {

        // if (p && p->left == NULL && p->right == NULL) {
		// 	return 0;
        // }
        if (p == NULL) {
			return 0;
        }
	
		// std::cout << "in getheight p content is : " << p->content.first << "\n";
		// int a = getHeight(p->left);
		// std::cout << "a : " << a << "\n";
		// int b = getHeight(p->right);
		// std::cout << "b : " << b << "\n";
    	return MAX(getHeight(p->left), getHeight(p->right)) + 1;
    	// return MAX(a, b) + 1;

        // int height = 0;
        // if (p != NULL) {
        //     height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
        // }
        // return height;
    }

    int getBF(node_pointer p) {
		// std::cout << "in getBF\n";
        if (p == NULL) {
            return 0;
        }
		// std::cout << "in getBF\n";
		// std::cout << "first p content is : " << p->content.first << "\n";
		// if (p->left)
		// 	std::cout << "first p's left content is : " << p->left->content.first << "\n";
		// if (p->right)
		// 	std::cout << "first p's right content is : " << p->right->content.first << "\n";
        return getHeight(p->left) - getHeight(p->right);
    }

    void deleteDummyNode() {
        node_pointer end = end_node();
        // std::cout << "end_node : " << end->content.first << "\n";
        // std::cout << " " << end->content.second << "\n";

        if (_size > 0) {
            end->parent->right = NULL;
            // std::cout << end->parent->content << "\n";
            end->parent = NULL;
            // _alloc.destroy(end);
            // _alloc.deallocate(end, 1);
        } else {
            // _alloc.deallocate(end, 1);
            _root = NULL;
        }
        // std::cout << "seperate dummy\n";
        // std::cout << "sdf\n";
        // TODO: 흠 delete .....
    }

    // void deleteRootDummyNode() {
    //     node_pointer end = end_node();
    //     // std::cout << "end_node : " << end->content.first << "\n";
    //     // std::cout << " " << end->content.second << "\n";

    //     if (_size > 0) {
    //         end->parent->right = NULL;
    //         // std::cout << end->parent->content << "\n";
    //         end->parent = NULL;
    //         // _alloc.destroy(end);
    //         _alloc.deallocate(end, 1);
    //     }
    //     // std::cout << "sdf\n";
    //     // TODO: 흠 delete .....
    // }

    void insertDummyNode() {
        // node_pointer dummy = _alloc.allocate(1);
        // _alloc.construct(dummy, node_type());

        // dummy->content = ft::make_pair(key_type(), mapped_type());
        // dummy->left = NULL;
        // dummy->right = NULL;
        _dummy->parent = end_node();
        _dummy->parent->right = _dummy;
        // std::cout << "put dummy\n";
    }

    node_pointer makeDummyNode() {
        node_pointer dummy = _alloc.allocate(1);
        _alloc.construct(dummy, node_type());

        dummy->content = ft::make_pair(key_type(), mapped_type());
        dummy->left = NULL;
        dummy->right = NULL;
        dummy->parent = NULL;

        return dummy;
    }

    node_pointer rebalance(node_pointer node) {
		// std::cout << "in rebalance\n";
        int BF = getBF(node);
		// std::cout << "BF is " << "\n";
        if (BF > 1) {

				// std::cout << "before \n";
            if (getBF((node)->left) > 0)
                node = llRotate(node);
            else
                node = lrRotate(node);
        } else if (BF < -1) {
            if (getBF((node)->right) < 0) {
				// std::cout << "before rr\n";
                node = rrRotate(node);
            } else {
                // std::cout << "before rlRR\n";
                node = rlRotate(node);
            }
        } else {
			
            // no rebalance
            // std::cout << "no rebalance\n";
        }
        return node;
    }

    void _setParent(node_pointer child, node_pointer parent) { child->parent = parent; }

    node_pointer _insertNode(node_pointer root, value_type content) {
        if (root == NULL) {
            root = _alloc.allocate(1);
            _alloc.construct(root, node_type());
            root->content = content;
            root->left = NULL;
            root->right = NULL;
            root->parent = NULL;
            _size++;
        }
        else if (_comp(content.first, root->content.first)) {
            root->left = _insertNode(root->left, content);
            _setParent(root->left, root);
            root = rebalance(root);
        }
        else if (_comp(root->content.first, content.first)) {
            root->right = _insertNode(root->right, content);
            _setParent(root->right, root);
            root = rebalance(root);
        } else {
            // printf("이미 같은 키가 있습니다.\n");
            // root->content = content;
        }
        return (root);
    }

    node_pointer _findTree(node_pointer root, key_type key) // const
    {
        node_pointer p;
        int count = 0;
        p = root;
        while (p != NULL) {
            count++;
            // if (content < p->content)
            if (_comp(key, p->content.first))
                p = p->left;
            else if (key == p->content.first) // TODO: comp ????
            {
                // printf("%3d번째에 성공", count);
                return p;
            } else
                p = p->right;
        }
        count++;
        return NULL; // 못찾으면 NULL 반환
    }

    node_pointer _findTree(node_pointer root, key_type key) const
    {
        node_pointer p;
        int count = 0;
        p = root;
        while (p != NULL) {
            count++;
            // if (content < p->content)
            if (_comp(key, p->content.first))
                p = p->left;
            else if (key == p->content.first) // TODO: comp ????
            {
                // printf("%3d번째에 성공", count);
                return p;
            } else
                p = p->right;
        }
        count++;
        return NULL; // 못찾으면 NULL 반환
    }

    void _disPlayInorder(node_pointer root) {
        if (root) {
            _disPlayInorder(root->left);
            if (root != end_node())
                std::cout << "key_type: " << root->content.first << "-" << root->content.second
                          << "\n";
            _disPlayInorder(root->right);
        }
    }

    void _disPlayInorder_for_debug(node_pointer root) {
        if (root) {
            _disPlayInorder_for_debug(root->left);
            if (root != _root) {
                // std::cout << "^_______^\n";
                std::cout << "key_type: " << root->content;
                if (root->parent)
                    std::cout << " and parent is " << root->parent->content << "\n";
                else
                    std::cout << "\n";
            } else
                std::cout << "key_type: " << root->content << " is real root \n";
            _disPlayInorder_for_debug(root->right);
        }
    }

    // find node that has a value one smaller than the node
    node_pointer _oneSmallerNode(node_pointer node) {
        node_pointer res = NULL;
        if (node->left) {
            res = node->left;
            while (res->right)
                res = res->right;
        }
        return res;
    }

    // find node that has a value one biger than the node
    node_pointer _oneBigerNode(node_pointer node) {
        node_pointer res = NULL;
        if (node->right) {
            res = node->right;
            while (res->left)
                res = res->left;
        }
        return res;
    }

    node_pointer _deleteNode(node_pointer root, key_type key) {
			// std::cout << "here node content is : " << root->content.first << "\n";
        if (root == NULL)
            return NULL;

        if (_comp(key, root->content.first)) {
			// std::cout << "hihi\n";
            root->left = _deleteNode(root->left, key);
            if (_root)
			{
				// std::cout << "before rebalance\n";
				// std::cout << "root content : " << root->content.first << "\n";
                root = rebalance(root);
				// std::cout << "after rebalance\n";
			}
			// std::cout << "herehere\n";
        } else if (_comp(root->content.first, key)) {
            root->right = _deleteNode(root->right, key);
            if (_root)
                root = rebalance(root);
        } else {
            if ((root->left == NULL) && (root->right == NULL)) // no child
            {
                // std::cout << "no child\n";
                // _alloc.deallocate(root, 1);
                root = NULL;
                _size--;
                // std::cout << "you\n";
            } else if ((root->left == NULL) || (root->right == NULL)) // one child
            {
                // std::cout << "one child\n";
                node_pointer child = NULL;
                if (root->left) {
                    child = root->left;
                } else {
                    child = root->right;
                }

                if (root->parent) {
                    child->parent = root->parent;
                    if (root->parent->right == root) {
                        root->parent->right = child;
                    } else {
                        root->parent->left = child;
                    }
                } else {
                    child->parent = NULL;
                }
                // _alloc.deallocate(root, 1);
                // root = NULL;
                _size--;
                return child;
            } else // two child
            {
                // std::cout << "two child\n";
                node_pointer child = NULL;
                child = _oneSmallerNode(root);
                // std::cout << "one SmalerNode : " << child->content.first << "\n";
                
                if (child->left == NULL && child->right == NULL) {
                    value_type tmp_content = root->content;
	    			root->content = child->content;
		    		child->content = tmp_content;
    
	    			if (child->parent->left == child)
		    			child->parent->left = NULL;
			    	else
				    	child->parent->right = NULL;
                    _alloc.deallocate(child, 1);
                }
                else // child가 자식이 하나 있을떄 
				{
                    node_pointer tmp = root;
				    if (child->left) {
                        child->left->parent = child->parent;
                        if (child->parent->left == child)
                            child->parent->left = child->left;
                        else
                            child->parent->right = child->left;
                    } else if (child->right) {
                        child->right->parent = child->parent;
                        if (child->parent->left == child)
                            child->parent->left = child->right;
                        else
                            child->parent->right = child->right;
                    }
                    
                    child->parent = tmp->parent;

                    if (tmp->left != child) {
                        child->left = tmp->left;
                        if (tmp->left != NULL) {
                           tmp->left->parent = child;
                        }
                    } else {
                       // child->left = NULL;
                    }
                    child->right = tmp->right;
                    if (tmp->right != NULL) {
                       tmp->right->parent = child;
                    }
                    root = child;
                    _alloc.deallocate(tmp, 1);
                }
                _size--;
            }
        }
// std::cout << "hihi\n";
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
    avlTree(const Compare &comp = Compare(), const Alloc &alloc = Alloc()) {
        _size = 0;
        _dummy = makeDummyNode();
        _root = _dummy;
        _comp = comp;
        _alloc = alloc;
        // _alloc = node_allocator();
    }

    avlTree(value_type content, const Compare &comp = Compare(), const Alloc &alloc = Alloc()) {
        _size = 0;
        _dummy = makeDummyNode();
        _root = _dummy;
        _comp = comp;
        _alloc = alloc;
        // _alloc = node_allocator();
        insertNode(content);
    }

    avlTree(node_pointer n, const Compare &comp = Compare(), const Alloc &alloc = Alloc()) {
        avlTree(n->content, comp, alloc);
    }

    avlTree(const avlTree &tree) //
    {
        *this = tree;
    }

    virtual ~avlTree() {
        // TODO: 소멸자 소환하기
        // 더미 노드 소멸시키기
    }

    avlTree &operator=(const avlTree &tree) // TODO: deep copy
    {
        _dummy = tree._dummy;
        _root = tree._root;
        _alloc = tree._alloc;
        _comp = tree._comp;
        _size = tree._size;

        return *this;
    }

    void insertNode(value_type content) {
        deleteDummyNode();
        // std::cout << "sdfsdf\n";
        _root = _insertNode(_root, content);
        insertDummyNode();
    }

    node_pointer findTree(key_type key) // const
    {
        return _findTree(_root, key);
    }

    node_pointer findTree(key_type key) const
    {
        return _findTree(_root, key);
    }

    // mapped_type &findNodeValue(key_type key)
    // {
    // 	return _findNodeValue(_root, key);
    // }

    void disPlayInorder() { _disPlayInorder(_root); }

    void deleteNode(key_type key) {
        deleteDummyNode();
        _root = _deleteNode(_root, key);
        if (_root)
            insertDummyNode();
        else
            _root = _dummy;
    }

    node_pointer begin_node() const {
        node_pointer current = _root;
        // if (size > 0)
        // std::cout << "current : " << current->content.first << "\n";
        while (current->left) {
            current = current->left;
            // std::cout << "current : " << current->content.first << "\n";
        }
        return current;
    }

    node_pointer end_node() const {
        node_pointer current = _root;

        while (current->right) {
            current = current->right;
        }
        return current;
    }

    size_type size() const { return _size; }

    // void clear()
    // {
    // 	deleteDummyNode();

    // 	// iterator it = begin();
    // 	// for (; it != end(); it++)
    // 	// {
    // 	// 	_alloc.destroy(it);
    // 	// 	_alloc.deallocate(it, 1);
    // 	// }
    // }

    void disPlayInorder_for_debug() { _disPlayInorder_for_debug(_root); }

    /*
    implement for tree:
     */

};
} // namespace ft

#endif