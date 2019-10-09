
#include "info.h"
#include "fixedstr.h"

#include <iostream>

int main()
{
  /*
  static char const name_ns[] = "ns";

  AttrInfo<name_ns> a;
  */

  static constexpr fixed_string name_ns{ "ns" };
  //AttrInfo<name_ns> a;

  std::cout << AttrInfo<name_ns>::offset << std::endl;

  return 0;
}
