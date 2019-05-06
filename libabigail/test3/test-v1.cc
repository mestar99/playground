
namespace v1 {
  struct S0
  {
    int m0;
  };

  void foo(S0& /* parameter_name */)
  {
    // do something with parameter_name
  }

  void baz()
  {

  }
}

inline
namespace v2 {

  using v1::baz;

  struct S0
  {
    char inserted_member;
    int m0;
  };

  void foo(S0& /* parameter_name */)
  {
    // do something with parameter_name
  }

  void bar(S0& /* parameter_name */)
  {
    // do something with parameter_name
  }
}
