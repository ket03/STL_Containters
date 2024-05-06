#ifndef LIST_HPP
#define LIST_HPP

#include <string>

template <typename T> class List {

public:
  List() : head_(nullptr), tail_(nullptr), current_(nullptr) {}

  ~List() {
    Node *ptr = head_;

    while (ptr) {
      Node *temp = ptr;
      ptr = ptr->next;
      delete temp;
    }
    tail_ = nullptr;
    head_ = nullptr;
    current_ = nullptr;
  }

  List(const List &other) {
    Node *ptr = other.head_;

    while (ptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  List(List &&other) : head_(other.head), tail_(other.tail_) {
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }

  void push_back(const T value) {
    Node *new_node = new Node();
    new_node->data = value;

    if (tail_ == nullptr) {
      head_ = new_node;
      tail_ = new_node;
      current_ = new_node;
    } else {
      tail_->next = new_node;
      tail_ = tail_->next;
    }
  }

  void pop_back() {
    IsCorrect();

    Node *ptr = head_;
    if (ptr == tail_) {
      delete tail_;
      tail_ = nullptr;
      head_ = nullptr;
    } else {
      while (ptr->next != tail_)
        ptr = ptr->next;
      delete tail_;
      tail_ = ptr;
      tail_->next = nullptr;
    }
  }

  void push_front(const T value) {
    Node *new_node = new Node();
    new_node->data = value;

    if (tail_ == nullptr) {
      head_ = new_node;
      tail_ = new_node;
      current_ = new_node;
    } else {
      new_node->next = head_;
      head_ = new_node;
    }
  }

  void pop_front() {
    IsCorrect();
    Node *temp = head_;
    head_ = head_->next;
    delete temp;

    if (head_ == nullptr)
      tail_ = nullptr;
  }

  T CurrentElement() {
    IsCorrect();
    return current_->data;
  }

  void Next() {
    IsCorrect();
    if (current_ == tail_)
      throw std::invalid_argument("current element already is last");
    current_ = current_->next;
  }

  void Back() {
    IsCorrect();
    if (current_ == head_)
      throw std::invalid_argument("current element already is first");
    Node *ptr = head_;
    while (ptr->next != current_)
      ptr = ptr->next;
    current_ = ptr;
  }

  void IsCorrect() {
    if (current_ == nullptr)
      throw std::invalid_argument("container is empty");
    if (tail_ == nullptr)
      throw std::invalid_argument("container is empty");
  }

  // void print() {
  //   Node *ptr = head_;
  //   while (ptr != nullptr) {
  //     std::cout << ptr->data << " ";
  //     ptr = ptr->next;
  //   }
  //   std::cout << std::endl;
  // }

private:
  struct Node {
    T data;
    Node *next;
  };

  Node *tail_; // указатель на последний элемент
  Node *head_; // указатель на первый элемент
  Node *current_; // текущий элемент
};

#endif // LIST_HPP