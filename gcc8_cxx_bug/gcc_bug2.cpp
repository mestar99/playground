struct A { template <long> void foo(); };
template <long t> auto bar() -> decltype( &A::foo<t>);
void foo()
{
  bar<0>();
}
