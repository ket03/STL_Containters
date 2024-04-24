#include <algorithm>
#include <iostream>
#include <string>

// исправить проблему с индексами
// сделать pop, clear, erase, size, empty, =, iterators

template <typename T> class Vector {
public:
  Vector() = default;
  ~Vector() = default;

  // other - rvalue. lvalue = rvalue
  Vector(const Vector &other) : size_(other.size_), capacity_(other.capacity_) {
    data = new T[capacity_];
    if (capacity_ > 0)
      std::copy(other.data, other.data + size_, data);
  }

  // other - rvalue. lvalue = rvalue, затем rvalue = nullptr
  Vector(Vector &&other) : size_(other.size_), capacity_(other.capacity_) {
    std::move(other.data, other.data + size_, data);
  }

  void push_back(const T &value) {
    size_++;
    if (size_ == capacity_) {
      capacity_ *= 2;
      T *reserve_data = new T[capacity_];
      for (size_t i = 0; i < size_ - 1; i++)
        reserve_data[i] = data[i];
      std::swap(reserve_data, data);
      delete[] reserve_data;
    }
    data[size_] = value;
  }

  void pop_back() {}

  T operator[](size_t index) { return data[index]; }

private:
  T *data = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 1;
};