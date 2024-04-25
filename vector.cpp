#include "vector.hpp"

int main() {
  Vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.resize(5);
  std::cout << a[2];

  std::cout << a.capacity();
}
