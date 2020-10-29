#include "vector.hpp"
#include <iostream>

int main() {
  ds::vector<int> vec(5);
  for (int i = 0; i < 5; ++i)
    vec[i] = i;
  for (int i = 0; i < 5; ++i)
    std::cout << vec[i] << (i == 4 ? '\n' : ' ');
}
