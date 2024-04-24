#include "vector.hpp"

int main() {
  Vector<int> a;
  a.push_back(1);
  a.push_back(2);
  Vector<int> b = std::move(a);
  std::cout << a[1];
}
