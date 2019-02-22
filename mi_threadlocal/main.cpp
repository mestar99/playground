
#include <iostream>
#include "mi_tls.hpp"

int main()
{
  mi_tls<int> counter = 123;

  std::cout << "counter 1: " << counter << std::endl;

  counter = static_cast<int>(counter)+1;

  std::cout << "counter 2: " << counter << std::endl;
}
