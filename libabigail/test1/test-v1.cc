
struct type_base
{
  int inserted;
};

struct S0 : public type_base
{
  int m0;
};

void foo(S0* /* parameter_name */ )
{
  // do something with parameter_name
}
