#include <iostream>

#include "delegate.hpp"

struct A
{
  void foo(int a)
  {
    std::cout << "method got: " << a << std::endl;
  }

  void foo(int a) const
  {
    std::cout << "const method got: " << a << std::endl;
  }

  void foo(int a) volatile
  {
    std::cout << "volatile method got: " << a << std::endl;
  }

  void foo(int a) const volatile
  {
    std::cout << "const volatile method got: " << a << std::endl;
  }
};

void foo(int a)
{
  std::cout << "function got: " << a << std::endl;
}

int main(int argc, char* argv[])
{
  auto d1(delegate<void (int)>::from<foo>());
  auto d1_1(delegate<void (int)>::from(foo));
  auto d1_2(delegate<void (int)>{foo});

  A a;
  auto d2(delegate<void (int)>::from<A, &A::foo>(&a));
  auto d2_1(delegate<void (int)>::from<A, static_cast< void(A::*)(int) const>(&A::foo)>(&a));
  auto d2_2(delegate<void (int)>::from<A, static_cast< void(A::*)(int) volatile>(&A::foo)>(&a));
  auto d2_3(delegate<void (int)>::from<A, static_cast< void(A::*)(int) const volatile>(&A::foo)>(&a));

  auto d4(delegate<void (int)>(&a, static_cast< void (A::*)(int)>(&A::foo)));
  auto d4_1(delegate<void (int)>(&a, static_cast< void(A::*)(int) const>(&A::foo)));
  auto d4_2(delegate<void (int)>(&a, static_cast< void(A::*)(int) volatile>(&A::foo)));
  auto d4_3(delegate<void (int)>(&a, static_cast< void(A::*)(int) const volatile>(&A::foo)));

  d1(1);
  d1_1(1);
  d1_2(1);

  d2(2);
  d2_1(2);
  d2_2(2);
  d2_3(2);

  d4(4);
  d4_1(4);
  d4_2(4);
  d4_3(4);
  
  int b(2);

  auto dx(delegate<void ()>(
    [b](){std::cout << "hello world: " << b << std::endl;}));

  dx();

  auto dy = delegate<void ()>::from(
    [b]() { std::cout << "goodbye world: " << b << std::endl; });

  dy();

  return 0;
}
