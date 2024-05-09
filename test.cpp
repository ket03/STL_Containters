// list, iterator, tree - set, insert_many vector

#include "stack.hpp"
#include <iostream>

int main() {
  Stack<int> a;
  a.push_back(1);
  Stack<int> b(std::move(a));
  
}