#include <algorithm>
#include <string>
// resize, shrink_to_fit, push_back
// исправить проблему с индексами
// сделать pop, clear, erase, size, empty, =, iterators
// подумать стоит ли выбрасывать ошибки при pop, clear если размер вектора = 0
// использование copy, move, swap
// оттестить всё !!!
// переместить функционал в сипипишник !!!

template <typename T> class Vector {
public:
  Vector() {
    data = new T[1];
    size_ = 0;
    capacity_ = 1;
  }

  ~Vector() {
    delete[] data;
    data = nullptr;
  }

  // other - rvalue. lvalue = rvalue
  Vector(const Vector &other) : size_(other.size_), capacity_(other.capacity_) {
    data = new T[capacity_];
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

  void push_back(const T value) {
    if (size_ == capacity_) {
      capacity_ *= 2;
      UseReserveStorage(capacity_);
    }
    data[size_] = value;
    size_++;
  }

  void pop_back() noexcept {
    if (size_ > 0) {
      data[size_ - 1] = 0;
      size_--;
    }
  }

  // не удаляет выделенную память, а лишь зануляет всё и сводит размер к 0
  void clear() noexcept {
    if (size_ > 0) {
      std::fill(data, data + size_, 0);
      size_ = 0;
    }
  }

  size_t size() noexcept { return size_; }

  bool empty() noexcept {
    if (size_)
      return false;
    return true;
  }

  void erase(const size_t index) noexcept {
    if (index <= size_) {
      for (size_t i = index; i < size_ - 1; i++)
        data[i] = data[i + 1];
      data[size_] = 0;
      size_--;
    }
  }

  // сводит capacity_ к size_. То есть уменьшает выделенную память под
  // количество использованных элементов
  void shrink_to_fit() {
    UseReserveStorage(size_);
    capacity_ = size_;
  }

  void operator=(const Vector &other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    data = new T[capacity_];
    std::copy(other.data, other.data + size_, data);
  }

  T operator[](const size_t index) {
    if (index >= size_)
      throw std::invalid_argument("index greater than size");
    return data[index];
  }

  void resize(const size_t new_size) {
    if (new_size <= size_)
      std::fill(data + new_size, data + size_, 0);
    else
      UseReserveStorage(new_size);
    size_ = new_size;
    capacity_ = new_size;
  }

  size_t capacity() noexcept { return capacity_; }

  // void push_back(many_arguments);

private:
  T *data;
  // основные взаимодействия приходится с size_. Очищение, добавление, удаление
  size_t size_; // размер вектора
  // capacity_ увеличивается лишь в случае, когда size_ = capacity_
  size_t capacity_; // выделенная память

  void UseReserveStorage(const size_t capacity) {
    T *reserve_data = new T[capacity_];
    std::copy(data, data + size_, reserve_data);
    std::swap(reserve_data, data);
    delete[] reserve_data;
  }
};