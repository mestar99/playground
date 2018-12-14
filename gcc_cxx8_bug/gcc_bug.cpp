// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=87513

template <int N> struct A { static constexpr int c = N; };
template <typename> struct B;
template <typename> struct C;
template <typename T, typename U> struct C<T U::*> : A<B<T>::c> {};
template <typename T, typename... U> struct B<T (U...)> : A<true> {};
template <typename> class D;
struct E { typedef int l; };
template <bool, bool, typename...> struct F;
template <typename T, typename U, typename... V> struct F<false, true, T, U, V...> : E {};
template <typename T, typename... U> struct G : F<A<false>::c, C<T>::c, U...> {};
template <typename T, typename... U> struct D<T (U...)> : G<T, U...> {};
struct H { H (const char *); };
struct I { template <long> void foo (); };
struct J { template <long t> auto bar (H) -> typename D<decltype (&I::foo<t>) (I, H)>::l; };
void
foo ()
{
  J j;
  j.bar<0> ("");
}
