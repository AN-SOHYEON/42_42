#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {

template <typename T>
class random_access_iterator {
   public:
    typedef T iterator_type;
    typedef typename ft::iterator_traits<T *>::value_type value_type;
    typedef typename std::random_access_iterator_tag iterator_category;
    typedef typename ft::iterator_traits<T *>::difference_type difference_type;
    typedef typename ft::iterator_traits<T *>::pointer pointer;
    typedef typename ft::iterator_traits<T *>::reference reference;

   private:
    pointer _p;

   public:
    random_access_iterator() : _p() {}

    random_access_iterator(pointer p) : _p(p) {}

    template <typename U>
    random_access_iterator(const random_access_iterator<U> &other) {
        _p = other.base();
    }

    pointer base() const {
        return _p;
    }

    virtual ~random_access_iterator() {}

    template <typename U>
    random_access_iterator &operator=(const random_access_iterator<U> &other) {
        _p = other.base();
        return *this;
    }

    reference operator*() const {
        return *_p;
    }

    pointer operator->() const {
        return _p;
    }

    reference operator[](difference_type n) const {
        return *(_p + n);
    }

    random_access_iterator &operator++() {
        _p++;
        return *this;
    }
    random_access_iterator operator++(int) {  // 후위 연산자
        random_access_iterator tmp(*this);
        _p++;
        return tmp;
    }

    random_access_iterator &operator--() {
        --_p;
        return *this;
    }
    random_access_iterator operator--(int) {  // 후위 연산자
        random_access_iterator tmp(*this);
        --_p;
        return tmp;
    }

    random_access_iterator operator+(difference_type n) const {
        return random_access_iterator(_p + n);
    }

    random_access_iterator operator-(difference_type n) const {
        return random_access_iterator(_p - n);
    }

    random_access_iterator &operator+=(difference_type n) {
        _p += n;
        return *this;
    }

    random_access_iterator &operator-=(difference_type n) {
        _p -= n;
        return *this;
    }
};

template <class Iter1, class Iter2>
bool operator==(const ft::random_access_iterator<Iter1> &lhs, const ft::random_access_iterator<Iter2> &rhs) {
    return lhs.base() == rhs.base();
}

template <class Iter1, class Iter2>
bool operator!=(const ft::random_access_iterator<Iter1> &lhs, const ft::random_access_iterator<Iter2> &rhs) {
    return lhs.base() != rhs.base();
}

template <class Iter1, class Iter2>
bool operator<(const ft::random_access_iterator<Iter1> &lhs, const ft::random_access_iterator<Iter2> &rhs) {
    return lhs.base() < rhs.base();
}

template <class Iter1, class Iter2>
bool operator<=(const ft::random_access_iterator<Iter1> &lhs, const ft::random_access_iterator<Iter2> &rhs) {
    return lhs.base() <= rhs.base();
}

template <class Iter1, class Iter2>
bool operator>(const ft::random_access_iterator<Iter1> &lhs, const ft::random_access_iterator<Iter2> &rhs) {
    return lhs.base() > rhs.base();
}

template <class Iter1, class Iter2>
bool operator>=(const ft::random_access_iterator<Iter1> &lhs, const ft::random_access_iterator<Iter2> &rhs) {
    return lhs.base() >= rhs.base();
}

template <class Iter>
random_access_iterator<Iter>
operator+(typename random_access_iterator<Iter>::difference_type n, const random_access_iterator<Iter> &it) {
    return random_access_iterator<Iter>(it.base() + n);
}

template <class Iter1, class Iter2>
typename random_access_iterator<Iter1>::difference_type
operator-(const random_access_iterator<Iter1> &lhs, const random_access_iterator<Iter2> &rhs) {
    return lhs.base() - rhs.base();
}

template <class Iter>  // TODO: fix!!!!!!!!!!!
random_access_iterator<Iter>
operator-(typename random_access_iterator<Iter>::difference_type n, const random_access_iterator<Iter> &it) {
    return random_access_iterator<Iter>(it.base() - n);
}
}  // namespace ft

#endif