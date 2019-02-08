
#include "lib.hpp"

#include <iostream>

namespace {

  bool checkForGCEInstance()
  {
    std::cout << "Inside checkForGCEInstance()" << std::endl;

    return true;
  }
}

bool const Lib::isRunningInGCE = checkForGCEInstance();

std::string Lib::getToken()
{
  if( isRunningInGCE ) {
    return "GCE";
  }
  else {
    return "Localhost";
  }
}
