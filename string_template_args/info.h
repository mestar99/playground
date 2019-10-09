
#ifndef INFO_H_
#define INFO_H_

#include <cstddef>

template <auto & input>
class AttrInfo
{
public:
  static std::size_t const offset = 123;
};

#endif
