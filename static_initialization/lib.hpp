
#pragma once

#include <string>

class Lib
{
public:
  std::string getToken();

private:
  static bool const isRunningInGCE;
};
