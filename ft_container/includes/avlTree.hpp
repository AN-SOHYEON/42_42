#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <functional>
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
        if (p == NULL) {
            return 0;
        }
        return MAX(getHeight(p->left), getHeight(p->right)) + 1;
    }

    int getBF(node_pointer p) {
        if (p == NULL) {
            return 0;
        }
        return getHeight(p->left) - getHeight(p->right);
    }

    void deleteDummyNode() {
        // node_pointer end = end_node();
        if (_size > 0) {
            _dummy->parent->right = NULL;
            _dummy->parent = NULL;
        } else {
            _root = NULL;
        }
    }

    void insertDummyNode() {
        _dummy->parent = end_node();
        _dummy->parent->right = _dummy;
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
        int BF = getBF(node);
        if (BF > 1) {
            if (getBF((node)->left) > 0)
                node = llRotate(node);
            else
                node = lrRotate(node);
        } else if (BF < -1) {
            if (getBF((node)->right) < 0) {
                node = rrRotate(node);
            } else {
                node = rlRotate(node);
            }
        }
        // else {
        // }
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
        } else if (_comp(content.first, root->content.first)) {
            root->left = _insertNode(root->left, content);
            _setParent(root->left, root);
            root = rebalance(root);
        } else if (_comp(root->content.first, content.first)) {
            root->right = _insertNode(root->right, content);
            _setParent(root->right, root);
            root = rebalance(root);
        }
        // else {
        // }
        return (root);
    }

    node_pointer _findTree(node_pointer root, key_type key) {
        node_pointer p;
        int count = 0;
        p = root;
        while (p != NULL) {
            count++;
            if (_comp(key, p->content.first))
                p = p->left;
            else if (key == p->content.first) {
                return p;
            } else
                p = p->right;
        }
        count++;
        return NULL;  // 못찾으면 NULL 반환
    }

    node_pointer _findTree(node_pointer root, key_type key) const {
        node_pointer p;
        int count = 0;
        p = root;
        while (p != NULL) {
            count++;
            if (_comp(key, p->content.first))
                p = p->left;
            else if (key == p->content.first) {
                return p;
            } else
                p = p->right;
        }
        count++;
        return NULL;
    }

    /*
    for check tree
     */
    void _disPlayInorder(node_pointer root) {
        if (root) {
            _disPlayInorder(root->left);
            if (root != end_node())
                std::cout << "key_type: " << root->content.first << "-" << root->content.second
                          << "\n";
            _disPlayInorder(root->right);
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
        if (root == NULL)
            return NULL;
        if (_comp(key, root->content.first)) {
            root->left = _deleteNode(root->left, key);
            if (_root) {
                root = rebalance(root);
            }
        } else if (_comp(root->content.first, key)) {
            root->right = _deleteNode(root->right, key);
            if (_root)
                root = rebalance(root);
        } else {
            if ((root->left == NULL) && (root->right == NULL))  // no child
            {
                _alloc.destroy(root);
                _alloc.deallocate(root, 1);
                root = NULL;
                _size--;
            } else if ((root->left == NULL) || (root->right == NULL))  // one child
            {
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
                _alloc.destroy(root);
                _alloc.deallocate(root, 1);
                _size--;
                return child;
            } else  // two child
            {
                node_pointer child = NULL;
                child = _oneSmallerNode(root);
                if (child->left == NULL && child->right == NULL) {
                    value_type tmp_content = root->content;
                    root->content = child->content;
                    child->content = tmp_content;
                    if (child->parent->left == child)
                        child->parent->left = NULL;
                    else
                        child->parent->right = NULL;
                    _alloc.destroy(child);
                    _alloc.deallocate(child, 1);
                } else  // child가 자식이 하나 있을떄
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
                    }
                    child->right = tmp->right;
                    if (tmp->right != NULL) {
                        tmp->right->parent = child;
                    }
                    root = child;
                    _alloc.destroy(tmp);
                    _alloc.deallocate(tmp, 1);
                }
                _size--;
            }
        }
        return root;
    }

   public:
    /*
    constuctor:
     */
    avlTree(const Compare &comp = Compare(), const Alloc &alloc = node_allocator()) {
        _size = 0;
        _dummy = makeDummyNode();
        _root = _dummy;
        _comp = comp;
        _alloc = alloc;
    }

    avlTree(value_type content, const Compare &comp = Compare(), const Alloc &alloc = node_allocator()) {
        _size = 0;
        _dummy = makeDummyNode();
        _root = _dummy;
        _comp = comp;
        _alloc = alloc;
        insertNode(content);
    }

    avlTree(node_pointer n, const Compare &comp = Compare(), const Alloc &alloc = node_allocator()) {
        avlTree(n->content, comp, alloc);
    }

    avlTree(const avlTree &tree) {
        *this = tree;
    }

    virtual ~avlTree() {
        if (_root && _root != _dummy) {
            clear();
        }
        _alloc.destroy(_dummy);
        _alloc.deallocate(_dummy, 1);
    }

    void clear() {
        deleteDummyNode();
        if (_root)
            _clear(&_root);
        _root = _dummy;
    }

    avlTree &
    operator=(const avlTree &tree) {
        _dummy = tree._dummy;
        _root = tree._root;
        _alloc = tree._alloc;
        _comp = tree._comp;
        _size = tree._size;
        return *this;
    }

    void insertNode(value_type content) {
        deleteDummyNode();
        _root = _insertNode(_root, content);
        insertDummyNode();
    }

    node_pointer findTree(key_type key) {
        return _findTree(_root, key);
    }

    node_pointer findTree(key_type key) const {
        return _findTree(_root, key);
    }

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
        while (current->left) {
            current = current->left;
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

    // TODO: private으로 옮기기
    void _clear(node_pointer *root) {
        if (*root) {
            _clear(&((*root)->left));
            _clear(&((*root)->right));
            node_pointer parent = (*root)->parent;
            if (parent) {
                if (parent->left == (*root)) {
                    // std::cout << "root content is : " << (*root)->content.first << "\n";
                    _alloc.destroy(*root);
                    // std::cout << "next\n";
                    _alloc.deallocate(*root, 1);
                    // std::cout << "last\n";
                    parent->left = NULL;
                    _size--;
                } else if (parent->right == (*root)) {
                    // std::cout << "root content is : " << (*root)->content.first << "\n";
                    _alloc.destroy(*root);
                    _alloc.deallocate(*root, 1);
                    parent->right = NULL;
                    _size--;
                }
            } else {
                // std::cout << "last node \n";
                // std::cout << "root content is : " << (*root)->content.first << "\n";
                _alloc.destroy(*root);
                _alloc.deallocate(*root, 1);
            }
        }
    }
};
}  // namespace ft

#endif