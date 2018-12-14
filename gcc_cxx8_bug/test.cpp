
#include "func.hpp"

class SpecialType
{
public:
  class SpecialTypeMetadataFactory
  {
  public:
    using value_type = int;
  };

  using MetadataFactory = SpecialTypeMetadataFactory;
};

int main()
{
  ns1::Stream s;
  int result = s.add<SpecialType>(std::string("abc"));

  std::cout << "result: " << result << std::endl;

  s.add<int>(std::string("def"));

  return 0;
}
