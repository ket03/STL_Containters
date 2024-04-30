#ifndef LIST_HPP
#define LIST_HPP

#include <string>
// утечка памяти - деструктор
// нормальный pop_back
// froonts
template <typename T> class List {

public:
  List() {
    size_ = 0;
    node = new Node();
    tail = new Node();
    head = new Node();
    node->data = T();
    node->next_ = nullptr;
    node->prev_ = nullptr;
  }

  ~List() {
    if (head) delete head;
    // if (tail) delete tail;
    // delete node;
  }

  List(const List &other) {}

  List(List &&other) {}

  void push_back(const T value) {
    if (size_ > 0) {
      Node *new_node = new Node();
      new_node->data = value;
      new_node->prev_ = node;
      node->next_ = new_node;
      node = new_node;
      tail = new_node;
    //   delete new_node;
    } else {
      node->data = value;
      head = node;
    }
    size_++;
  }

  void pop_back() {
    if (size_ > 1) {
      tail = tail->prev_;
      tail->next_ = nullptr;
      node = tail;
    } else if (size_ == 1) {
      tail = nullptr;
      head = nullptr;
      node = nullptr;
    } else if (size_ == 0) {
      throw std::range_error("can't delete empty list");
    }
    size_--;
  }

  void push_front() {}

  void pop_front() {}

  void next() {
    if (node != tail)
      node = node->next_;
    throw std::range_error("iterator on highest index");
  }

  void prev() {
    if (node != head)
      node = node->prev_;
    throw std::range_error("iterator on lowest index");
  }

  T getData() {
    if (node)
        return node->data;
    else throw std::range_error("list is empty");
  }

private:
  struct Node {
    T data;
    Node *next_;
    Node *prev_;
  };

  size_t size_;
  Node *node;
  Node *tail;
  Node *head;
};

#endif // LIST_HPP