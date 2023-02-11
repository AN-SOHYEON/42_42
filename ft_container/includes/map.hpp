#ifndef MAP_HPP
#define MAP_HPP

#include <functional>  // std::less
#include <map>
#include <memory>
#include <utility>

#include "avlTree.hpp"
#include "bidirectional_iterator.hpp"
#include "utility.hpp"

namespace ft {
template <class Key, class Value,
          class Compare = std::less<Key>,  // map의 정렬 기준 조건자
          class Allocator = std::allocator<ft::pair<const Key, Value> > >
class map {
   public:
    typedef Key key_type;
    typedef Value mapped_type;
    typedef typename ft::pair<const key_type, mapped_type> value_type;
    typedef typename std::size_t size_type;
    typedef typename std::ptrdiff_t difference_type;
    typedef Compare key_compare;
    typedef Allocator allocator_type;
    typedef typename allocator_type::template rebind<ft::Node<key_type, value_type> >::other node_allocator;

    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef typename node_allocator::pointer pointer;
    typedef typename node_allocator::const_pointer const_pointer;

    typedef typename ft::bidirectional_iterator<key_type, mapped_type> iterator;
    typedef typename ft::bidirectional_iterator<const key_type, const mapped_type> const_iterator;
    typedef typename ft::reverse_iterator<iterator> reverse_iterator;
    typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

    typedef typename ft::avlTree<key_type, mapped_type, Compare, Allocator> tree;
    typedef typename ft::Node<key_type, mapped_type> node;

    class value_compare : public std::binary_function<value_type, value_type, bool> {
        friend class map;
        // map 클래스의 모든 멤버 함수는 value_compare 클래스에 대한 프렌드 접근 권한을 부여받는다.

       protected:
        key_compare comp;
        value_compare(key_compare c) : comp(c) {}
        value_compare() {}  // TODO: ?????이게 왜 있어야 하는 거지 나는?

       public:
        bool operator()(const value_type &x, const value_type &y) const {
            return comp(x.first, y.first);
        }
    };

   protected:
    tree _tree;
    node_allocator _alloc;
    key_compare _key_comp;
    value_compare _value_comp;

    template <typename U>
    void _swap(U &a, U &b) {
        U tmp = a;
        a = b;
        b = tmp;
    }

   public:
    tree &__get_tree() { return _tree; }

    explicit map(const Compare &comp = key_compare(), const Allocator &alloc = node_allocator()) {
        _alloc = alloc;
        _key_comp = comp;
        _value_comp = value_compare(comp);
    }

    template <class InputIt>
    map(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last, const Compare &comp = key_compare(), const Allocator &alloc = node_allocator()) {
        _alloc = alloc;
        _key_comp = comp;
        _value_comp = value_compare(comp);
        _tree = tree(_key_comp, _alloc);
        insert(first, last);
    }

    // map(const map &other)
    //     : _alloc(other._alloc), _key_comp(other._key_comp), _value_comp(other._value_comp) {
    //     std::cout << "fuck\n";
    //     _tree = tree(_key_comp, _alloc);
    //     std::cout << "fuckfuckfuck\n";
    //     insert(other.begin(), other.end());
    //     std::cout << "fuckfuckfuckyoyoyoyououyou\n";
    // }
    map(const map &other) {
        // std::cout << "in copy constructor\n";
        _alloc = other._alloc;
        _key_comp = other._key_comp;
        _value_comp = other._value_comp;

        // _tree = tree(_key_comp, _alloc);
        // std::cout << "fucking\n";
        *this = other;
    }

    virtual ~map() {
    }

    map &
    operator=(const map &other) {
        clear();
        _alloc = other._alloc;
        _key_comp = other._key_comp;
        _value_comp = other._value_comp;
        // _tree = tree(_key_comp, _alloc);
        insert(other.begin(), other.end());
        return (*this);
    }

    allocator_type get_allocator() const { return _alloc; }

    mapped_type &at(const key_type &key) {
        node *n = _tree.findTree(key);
        if (n == NULL)
            throw std::out_of_range("map over");
        return n->content->second;
    }

    const mapped_type &at(const key_type &key) const {
        node *n = _tree.findTree(key);
        if (n == NULL)
            throw std::out_of_range("map over");
        return n->content->second;
    }

    mapped_type &operator[](const key_type &key) {
        node *n = _tree.findTree(key);
        if (!n) {
            ft::pair<key_type, mapped_type> p = ft::make_pair(key, mapped_type());
            _tree.insertNode(p);
        }
        n = _tree.findTree(key);
        return (n->content.second);
    }

    /*
    iterator:
     */
    iterator begin() { return iterator(this->_tree.begin_node()); }

    const_iterator begin() const {
        return iterator(this->_tree.begin_node());
    }

    iterator end() { return iterator(this->_tree.end_node()); }

    const_iterator end() const {
        return iterator(this->_tree.end_node());
    }

    reverse_iterator rbegin() { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const { return reverse_iterator(end()); }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const { return reverse_iterator(begin()); }

    /*
    capacity:
     */
    bool empty() const {
        return (begin() == end());
    }

    size_type size() const {
        return _tree.size();
    }

    size_type max_size() const { return _alloc.max_size(); }

    /*
    modifiers:
     */
    void clear() {
        // iterator it = begin();
        // iterator tmp;

        // while (it != end()) {
        //     tmp = it;
        //     it++;
        //     erase(tmp);
        // }
        _tree.clear();
    }

    ft::pair<iterator, bool> insert(const value_type &value) {
        bool insert_res;
        node *n = _tree.findTree(value.first);

        if (n) {
            insert_res = false;
        } else {
            insert_res = true;
            _tree.insertNode(value);
            n = _tree.findTree(value.first);
        }
        iterator it(n);

        return ft::make_pair<iterator, bool>(it, insert_res);
    }

    iterator insert(iterator pos, const value_type &content) {
        (void)pos;
        _tree.insertNode(content);
        return iterator(_tree.findTree(content.first));
    }

    template <class InputIt>
    void insert(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last) {
        InputIt it = first;
        while (it != last) {
            _tree.insertNode(*it);
            it++;
        }
    }

    void erase(iterator pos) {
        _tree.deleteNode(pos->first);
    }

    void erase(iterator first, iterator last) {
        iterator it = first;
        iterator tmp;

        while (it != last) {
            tmp = it;
            ++it;
            erase(tmp);
        }
    }

    size_type erase(const key_type &key) {
        node *n = _tree.findTree(key);
        if (n) {
            iterator it(n);
            erase(it);
            return 1;
        }
        return 0;
    }

    void swap(map &other) {  // TODO: treeswap
        map tmp(other);
        // std::cout << "copy contructor\n";
        // other._tree = _tree;
        // _tree = tmp._tree;

        // std::cout << "tmp\n";
        // tmp.__get_tree().disPlayInorder();
        // std::cout << "other\n";
        // other.__get_tree().disPlayInorder();
        // std::cout << "----------------------\n";

        // other.erase(other.begin());
        // std::cout << "tmp\n";
        // tmp.__get_tree().disPlayInorder();
        // std::cout << "other\n";
        // other.__get_tree().disPlayInorder();

        // std::cout << "1\n";
        // other = *this;
        // std::cout << "2\n";
        // *this = tmp;
        // std::cout << "3\n";

        // tree tmp = tree(_key_comp, _alloc);
        // tmp.in
        // _tree = other._tree;
        // other._tree = tmp;
        // std::cout << "wer\n";
        // _swap(_tree, tmp._tree);
        _swap(_alloc, tmp._alloc);
        _swap(_key_comp, tmp._key_comp);
        _swap(_value_comp, tmp._value_comp);
    }

    /*
    Lookup:
     */
    // 키가 매개 변수에서 지정한 키와 일치하는 map의 요소 수를 반환.
    size_type count(const key_type &key) const {
        if (_tree.findTree(key))
            return 1;
        return 0;
    }

    iterator find(const key_type &key) {
        node *n = _tree.findTree(key);
        if (n)
            return iterator(_tree.findTree(key));
        return end();
    }

    const_iterator find(const key_type &key) const {
        node *n = _tree.findTree(key);

        if (n)
            return iterator(_tree.findTree(key));
        return end();
    }

    // key의 반복자 구간인 pair 객체
    ft::pair<iterator, iterator> equal_range(const key_type &key) {
        return ft::make_pair(lower_bound(key), upper_bound(key));
    }

    ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const {
        return ft::make_pair(lower_bound(key), upper_bound(key));
    }

    // key의 시작 구간을 가리키는 반복자/ key와 같거나 바로 다음 큰값
    iterator lower_bound(const key_type &key) {
        iterator iter = begin();
        while (iter != end()) {
            if (iter->first >= key)
                return iter;
            ++iter;
        }
        return end();
    }

    const_iterator lower_bound(const key_type &key) const {
        const_iterator iter = begin();
        while (iter != end()) {
            if (iter->first >= key)
                return iter;
            ++iter;
        }
        return end();
    }

    // key 바로 다음 큰 값
    iterator upper_bound(const key_type &key) {
        iterator iter = begin();

        for (; iter != end(); iter++) {
            if (iter->first > key)
                return iter;
        }
        return end();
    }

    const_iterator upper_bound(const key_type &key) const {
        const_iterator iter = begin();
        for (; iter != end(); iter++) {
            if (iter->first > key)
                return iter;
        }
        return end();
    }

    /*
    Observers:
     */
    // key 정렬 기준인 조건자를 반환
    key_compare key_comp() const { return _key_comp; }

    // value 정렬 기준인 조건자를 반환
    value_compare value_comp() const { return _value_comp; }
};

/* non member function */
template <class Key, class Value, class Compare, class Alloc>
bool operator==(const ft::map<Key, Value, Compare, Alloc> &lhs,
                const ft::map<Key, Value, Compare, Alloc> &rhs) {
    return ((lhs.size() == rhs.size()) && (ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
}

template <class Key, class Value, class Compare, class Alloc>
bool operator!=(const ft::map<Key, Value, Compare, Alloc> &lhs,
                const ft::map<Key, Value, Compare, Alloc> &rhs) {
    return !(lhs == rhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator<(const ft::map<Key, Value, Compare, Alloc> &lhs,
               const ft::map<Key, Value, Compare, Alloc> &rhs) {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class Value, class Compare, class Alloc>
bool operator<=(const ft::map<Key, Value, Compare, Alloc> &lhs,
                const ft::map<Key, Value, Compare, Alloc> &rhs) {
    return !(rhs < lhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator>(const ft::map<Key, Value, Compare, Alloc> &lhs,
               const ft::map<Key, Value, Compare, Alloc> &rhs) {
    return (rhs < lhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator>=(const ft::map<Key, Value, Compare, Alloc> &lhs,
                const ft::map<Key, Value, Compare, Alloc> &rhs) {
    return !(lhs < rhs);
}

template <class Key, class Value, class Compare, class Alloc>
void swap(ft::map<Key, Value, Compare, Alloc> &lhs, ft::map<Key, Value, Compare, Alloc> &rhs) {
    lhs.swap(rhs);
}

}  // namespace ft

#endif