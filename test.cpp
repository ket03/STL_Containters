#include "stack.hpp"
#include <iostream>
// #include "vector.hpp"

int main() {
  Stack<int> test;
  test.push_back(1);
  test.push_back(2);
  test.pop_back();
//   test.erase(1);
  std::cout << test.top();
}