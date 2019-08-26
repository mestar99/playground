
#include <iostream>
#include <array>

//class [[gnu::packed]] int24_t
class int24_t
{
public:
  unsigned int val : 24;
};

struct S
{
  unsigned char b1:3,:2,b2:6,b3:2;
};

int main()
{
  std::cout << sizeof(S) << '\n';

  int24_t a;
  a.val = 0;

  std::cout << "sizeof: " << sizeof(int24_t) << std::endl;

  for(unsigned int i=0; i < 10; ++i) {
    std::cout << a.val++ << std::endl;
  }

  std::array<int24_t,12> arr_a;
  //arr_a[0] = a;
  //arr_a[1] = a;

  std::cout << "sizeof array: " << sizeof(arr_a) << std::endl;

  return 0;
}
