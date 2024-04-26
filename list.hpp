#ifndef LIST_HPP
#define LIST_HPP

#include <string>

template <typename T>
class List {

public:
    List() {
        size_ = 0;
        node->data = T();
        node->next = nullptr;
    }

    ~List() {}

    List(const List &other) {}

    List(List &&other) {}

    void push_back(const T value) {
        if (size_ > 0) {
            Node *new_node = new Node();

// prev

            new_node->data = value;
            node->next = new_node;
            node = new_node;
        } else node->data = value;
        size_++;
    }

    void pop_back() {}
    void push_front() {}
    void pop_front() {}

    T getData() {
        return node->data;
    }

    T operator[](const size_t index) {
        for (size_t i = 0; i < index; i++) {
            node = node->next;
        }
        return node->data;
    }

private:
    struct Node {
        T data;
        Node *next;
        Node *prev;
    };

    size_t size_;
    Node *node = new Node();
};

#endif // LIST_HPP