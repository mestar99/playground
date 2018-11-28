
#include <iostream>
#include <string>

void print(std::string const & val)
{
  std::cout << val << std::endl;
}

extern "C" {
  void load(char const * str) {
    print(std::string(str));
  }
}
