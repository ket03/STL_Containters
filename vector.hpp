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
  // не работает
  Vector(Vector &&other) : size_(other.size_), capacity_(other.capacity_) {
    data = new T[capacity_];
    std::swap(other.data, data);
    other.data = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }

  void push_back(const T &value) {
    if (size_ + 1 == capacity_) {
      capacity_ *= 2;
      T *reserve_data = new T[capacity_];
      for (size_t i = 0; i < size_; i++)
        reserve_data[i] = data[i];
      std::swap(reserve_data, data);
      delete[] reserve_data;
    }
    data[size_] = value;
    size_++;
  }

  void pop_back() {

  }

  T operator[](size_t index) {
    if (index >= size_)
      throw std::invalid_argument("index greater than size");
    return data[index];
  }

private:
  T *data = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 1;
};