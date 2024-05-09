#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

template <typename T> class Stack {

public:
  Stack() = default;
  ~Stack() = default;

  Stack(const Vector &other) {}

  Stack(Stack &&other) {}

  Stack(const std::initializer_list<T> &values) {}

  T top() noexcept { return vector[vector.size() - 1]; }

  bool empty() noexcept { return vector.empty(); }

  size_t size() noexcept { return vector.size(); }

  void push_back(const T value) { vector.push_back(value); }

  void pop_back() noexcept { vector.pop_back(); }

private:
  Vector<T> vector;
};

#endif // STACK_HPP