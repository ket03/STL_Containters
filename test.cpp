// list, iterator, tree - set, insert_many vector

#include "list.hpp"
#include <iostream>

int main() {
    List<int> test;
     test.push_back(1);
          test.push_back(2);
               test.push_back(3);
     test.push_back(4);
     std::cout << test.getData();
}