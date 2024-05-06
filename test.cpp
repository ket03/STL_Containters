// list, iterator, tree - set, insert_many vector

#include "list.hpp"
#include <iostream>

int main() {
  List<int> a;
  a.push_back(1);
    a.push_back(2);
    a.Next();
    a.Back();
  std::cout << a.CurrentElement();
}