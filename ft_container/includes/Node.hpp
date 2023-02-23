#ifndef NODE_HPP
#define NODE_HPP

#include "utility.hpp"

namespace ft {

template <typename Key, typename Value>
struct Node {
    ft::pair<Key, Value> content;
    struct Node *left;
    struct Node *right;
    struct Node *parent;

    Node() {}

    template <typename K, typename V>
    Node(const Node<K, V> &other)
        : content(other.content), left(other.left), right(other.right), parent(other.parent) {}

    virtual ~Node() {}

    Node &operator=(const Node &other) {
        content = other.content;
        left = other.left;
        right = other.right;
        parent = other.parent;
        return *this;
    }
};

template <class K, class V>
bool operator==(const Node<K, V> &lhs, const Node<K, V> &rhs) {
    return (lhs->content == rhs->content);
}

template <class K, class V>
bool operator!=(const Node<K, V> &lhs, const Node<K, V> &rhs) {
    return (lhs->content != rhs->content);
}

template <class K, class V>
bool operator>(const Node<K, V> &lhs, const Node<K, V> &rhs) {
    return (lhs->content > rhs->content);
}

template <class K, class V>
bool operator>=(const Node<K, V> &lhs, const Node<K, V> &rhs) {
    return (lhs->content >= rhs->content);
}

template <class K, class V>
bool operator<=(const Node<K, V> &lhs, const Node<K, V> &rhs) {
    return (lhs->content <= rhs->content);
}

template <class K, class V>
bool operator<(const Node<K, V> &lhs, const Node<K, V> &rhs) {
    return (lhs->content < rhs->content);
}
}  // namespace ft

#endif
