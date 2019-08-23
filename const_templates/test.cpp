
#include <iostream>
#include <type_traits>
#include <string>
#include <cxxabi.h>

/*
template <typename _Tp>
struct demo
{
  //static_assert(std::is_const<_Tp const>::value,"");
  static_assert(std::is_function<_Tp>::value,"");
};

//demo<int const> d1;
//demo<int> d2;
demo<int(*)()> d3;
*/

template <typename T>
struct remove_member_pointer { using type = T; };

template <typename T, typename U>
struct remove_member_pointer<U T::*> { using type = U; };

template <typename T>
using remove_member_pointer_t = typename remove_member_pointer<T>::type;

struct A {
  int fun() const &;
  int fun2();
};

int f();

int main()
{
  std::cout << std::boolalpha;
  std::cout << std::is_function_v<A> << '\n';
  std::cout << std::is_function_v<int(int)> << '\n';
  std::cout << std::is_function_v<decltype(f)> << '\n';
  std::cout << std::is_function_v<int> << '\n';
  std::cout << std::is_function_v<remove_member_pointer_t<decltype(&A::fun)>> << '\n';

  using memtype = remove_member_pointer_t<decltype(&A::fun2)>;
  std::cout<<abi::__cxa_demangle(typeid(memtype).name(),0,0,0)<<'\n';
}
