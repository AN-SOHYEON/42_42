#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T> >
class stack {
   public:
    typedef Container container_type;
    typedef typename Container::value_type value_type;
    typedef typename Container::size_type size_type;
    typedef typename Container::reference reference;
    typedef typename Container::const_reference const_reference;

   protected:
    container_type _content;

   public:
    explicit stack(const Container &cont = Container()) {
        _content = cont;
    }

    stack &operator=(const stack &other) {
        _content = other._content;
        return (*this);
    }

    reference top() {
        return (_content.back());
    }

    const_reference top() const {
        return (_content.back());
    }

    bool empty() const {
        if (_content.empty())
            return true;
        return false;
    }

    size_type size() const {
        return (_content.size());
    }

    void push(const value_type &value) {
        _content.push_back(value);
    }

    void pop() {
        _content.pop_back();
    }

    friend bool operator==(const stack &lhs, const stack &rhs) {
        return (lhs._content == rhs._content);
    }

    friend bool operator!=(const stack &lhs, const stack &rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const stack &lhs, const stack &rhs) {
        return (lhs._content < rhs._content);
    }

    friend bool operator<=(const stack &lhs, const stack &rhs) {
        return (lhs._content <= rhs._content);
    }

    friend bool operator>(const stack &lhs, const stack &rhs) {
        return (lhs._content > rhs._content);
    }

    friend bool operator>=(const stack &lhs, const stack &rhs) {
        return (lhs._content >= rhs._content);
    }
};

}  // namespace ft

#endif