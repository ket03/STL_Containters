#ifndef SET_HPP
#define SET_HPP

#include "tree.hpp"

template <typename T>
class Set {

public:
    Set() {}
    ~Set() {}
    Set(const Set &other) {}
    Set(Set &&other) {}
    Set(const std::initializer_list<T> &values) {}

private:
};

#endif // SET_HPP