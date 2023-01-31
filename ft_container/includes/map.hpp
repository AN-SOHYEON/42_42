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
    typedef typename allocator_type::template rebind<ft::Node<key_type, value_type> >::other
        node_allocator;
    // typedef typename allocator_type::template rebind<ft::node<value_type> >::other
    // node_allocator;

    typedef value_type &reference;
    typedef const value_type &const_reference;
    // typedef typename Allocator::pointer pointer;
    typedef typename node_allocator::pointer pointer;              // TODO:
    typedef typename node_allocator::const_pointer const_pointer;  // TODO:

    typedef typename ft::bidirectional_iterator<key_type, mapped_type> iterator;
    typedef typename ft::bidirectional_iterator<const key_type, const mapped_type> const_iterator;
    typedef typename ft::reverse_iterator<iterator> reverse_iterator;
    typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

    // typedef typename ft::avlTree<value_type, key_type, Compare, Allocator> tree;
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
    node_allocator _alloc;  // TODO: 둘지말지 고민하기
    key_compare _key_comp;
    value_compare _value_comp;

    // template <class InputIterator> // node 기반 컨테이너는 이터레이터간의 거리를 뺄셈으로 구할 수
    // 없다. typename iterator_traits<InputIterator>::difference_type _distance(InputIterator first,
    // InputIterator last)
    // {
    // 	typename iterator_traits<InputIterator>::difference_type n = 0;
    // 	while (first != last)
    // 	{
    // 		first++;
    // 		n++;
    // 	}
    // 	return (n);
    // }

    template <typename U>
    void _swap(U &a, U &b) {
        U tmp = a;
        a = b;
        b = tmp;
    }

   public:
    // map()
    // {
    // 	// _tree = NULL;
    // 	_alloc = node_allocator();
    // 	_key_comp = key_compare();
    // 	_value_comp = value_compare(_key_comp);
    // }

    tree &__get_tree() { return _tree; }

    explicit map(const Compare &comp = key_compare(), const Allocator &alloc = allocator_type()) {
        // _tree = NULL;
        _alloc = alloc;
        _key_comp = comp;
        _value_comp = value_compare(comp);
    }

    template <class InputIt>
    map(InputIt first, InputIt last, const Compare &comp = key_compare(),
        const Allocator &alloc = allocator_type(),
        typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = NULL) {
        _alloc = alloc;  // TODO: 아ㅏㅏㅏ allocator 모르겠는디ㅣㅣㅣ ㅇㅈ
        _key_comp = comp;
        _value_comp = value_compare(comp);
        _tree = tree(_key_comp, _alloc);
        // std::cout << "sdjksdhf\n";
        insert(first, last);
    }

    map(const map &other)
        : _alloc(other._alloc), _key_comp(other._key_comp), _value_comp(other._value_comp) {
        _tree = tree(_key_comp, _alloc);
        *this = other;
    }

    virtual ~map() {
        // _tree.clear
    }

    map &operator=(const map &other) {
        _alloc = other._alloc;
        _key_comp = other._key_comp;
        _value_comp = other._value_comp;
        _tree = tree(_key_comp, _alloc);
        // *this = other;
        insert(other.begin(), other.end());
        return (*this);
    }

    allocator_type get_allocator() const { return _alloc; }

    mapped_type &at(const key_type &key) {
        node *n = _tree.findTree(key);

        if (n == NULL) throw std::out_of_range("map over");
        return n->content->second;
    }

    const mapped_type &at(const key_type &key) const {
        node *n = _tree.findTree(key);

        if (n == NULL) throw std::out_of_range("map over");
        return n->content->second;
    }

    mapped_type &operator[](const key_type &key) {
        node *n = _tree.findTree(key);
        if (n)  // 있는 인덱스면
        {
            erase(iterator(n));
        }
        ft::pair<key_type, mapped_type> p = ft::make_pair(key, mapped_type());
        // std::cout << "you\n";
        _tree.insertNode(p);
        n = _tree.findTree(key);

        return (n->content.second);
    }

    /*
    iterator:
     */
    iterator begin() { return iterator(this->_tree.begin_node()); }
    const_iterator begin() const {
        // return const_iterator(this->_tree.begin_node());
        return iterator(this->_tree.begin_node());
    }

    iterator end() { return iterator(this->_tree.end_node()); }

    const_iterator end() const {
        // return const_iterator(this->_tree.end_node());
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
        // if (begin() == end())
        // 	return true;
        // return false;
    }

    size_type size() const {
        // std::cout << "in map size : " << _tree.size() << "\n";
        return _tree.size();
    }

    size_type max_size() const { return _alloc.max_size(); }

    /*
    modifiers:
     */
    // 모든 원소 제거
    void clear() {
        iterator it = begin();
        iterator tmp;

        while (it != end()) {
            tmp = it;
            it++;
            erase(tmp);
        }
        // _tree.clear();
    }

    ft::pair<iterator, bool> insert(const value_type &value) {
        // iterator it;
        bool insert_res;
        node *n = _tree.findTree(value.first);
        if (n) {
            insert_res = false;
        } else {
            insert_res = true;
            _tree.insertNode(value);
            // std::cout << "wdfwdfwdfwdf\n";
            n = _tree.findTree(value.first);
        }
        iterator it(n);

        return ft::make_pair<iterator, bool>(it, insert_res);
    }

    iterator insert(iterator pos, const value_type &content) {
        (void)pos;
        // return iterator(_tree.insertNode(value));
        _tree.insertNode(content);

        return iterator(_tree.findTree(content.first));
    }

    template <class InputIt>
    void insert(InputIt first, InputIt last) {
        InputIt it = first;

        // std::cout << "first : " << first->first << "\n";
        // std::cout << "last  : " << last->first << "\n";
        // std::cout << "same  : " << (first == last) << "\n";
        // std::cout << "same2  : " << (first->first == last->first) << "\n";

        // int bomb_count = 15;
        while (it != last) {
            // std::cout << "it->first" << it->first << "\n";
            _tree.insertNode(*it);
            // std::cout << "hihihi\n";
            ++it;
            // bomb_count--;
            // if (bomb_count < 0)
            // break;
        }
    }

    void erase(iterator pos) {
        _tree.deleteNode(pos->first);
        // (void)pos;
    }

    void erase(iterator first, iterator last) {
        iterator it = first;
        iterator tmp;

        while (it != last) {
            tmp = it;
            std::cout << "heere???? " << (*tmp).first << "\n";
            ++it;
            erase(tmp);
        }
    }

    size_type erase(const key_type &key)  // TODO: 구현하기
    {
        node *n = _tree.findTree(key);

        if (n) {
            iterator it(n);
            erase(it);
        }
    }

    void swap(map &other) {
        _swap(_tree, other._tree);
        _swap(_alloc, other._alloc);
        _swap(_key_comp, other._key_comp);
        _swap(_value_comp, other._value_comp);
    }

    /*
    Lookup:
     */
    // 키가 매개 변수에서 지정한 키와 일치하는 map의 요소 수를 반환.
    size_type count(const key_type &key) const {
        if (_tree.findTree(key)) return 1;
        return 0;
    }

    iterator find(const key_type &key) {
        node *n = _tree.findKey(key);

        if (n) return iterator(_tree.findTree(key));
        return end();
    }

    const_iterator find(const key_type &key) const {
        node *n = _tree.findTree(key);

        if (n) return const_iterator(_tree.findTree(key));
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
            if (iter->first >= key) return iter;
            ++iter;
        }
        return end();
    }

    const_iterator lower_bound(const key_type &key) const {
        const_iterator iter = begin();
        // node *stad = _tree.findTree(key);

        while (iter != end()) {
            if (iter->first >= key) return iter;
            ++iter;
        }
        return end();
    }

    // key 바로 다음 큰 값
    iterator upper_bound(const key_type &key) {
        iterator iter = begin();

        for (; iter != end(); iter++) {
            if (iter->first > key) return iter;
        }
        return end();
    }

    const_iterator upper_bound(const key_type &key) const {
        const_iterator iter = begin();
        // node *stad = _tree.findTree(key);

        for (; iter != end(); iter++) {
            if (iter->first > key) return iter;
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
bool operator==(const std::map<Key, Value, Compare, Alloc> &lhs,
                const std::map<Key, Value, Compare, Alloc> &rhs) {
    return ((lhs.size() == rhs.size()) && (ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
}

template <class Key, class Value, class Compare, class Alloc>
bool operator!=(const std::map<Key, Value, Compare, Alloc> &lhs,
                const std::map<Key, Value, Compare, Alloc> &rhs) {
    return !(lhs == rhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator<(const std::map<Key, Value, Compare, Alloc> &lhs,
               const std::map<Key, Value, Compare, Alloc> &rhs) {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class Value, class Compare, class Alloc>
bool operator<=(const std::map<Key, Value, Compare, Alloc> &lhs,
                const std::map<Key, Value, Compare, Alloc> &rhs) {
    return !(rhs < lhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator>(const std::map<Key, Value, Compare, Alloc> &lhs,
               const std::map<Key, Value, Compare, Alloc> &rhs) {
    return (rhs < lhs);
}

template <class Key, class Value, class Compare, class Alloc>
bool operator>=(const std::map<Key, Value, Compare, Alloc> &lhs,
                const std::map<Key, Value, Compare, Alloc> &rhs) {
    return !(lhs < rhs);
}

template <class Key, class Value, class Compare, class Alloc>
void swap(std::map<Key, Value, Compare, Alloc> &lhs, std::map<Key, Value, Compare, Alloc> &rhs) {
    lhs.swap(rhs);
}

}  // namespace ft

#endif