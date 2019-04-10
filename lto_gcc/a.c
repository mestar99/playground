
#include "a.h"

static int i = 0;

void foo2()
{
  i = -1;
}

static int foo3()
{
  foo4();
  return 10;
}

int foo1()
{
  int data = 0;

  if(i < 0)
    data = foo3();

  data = data + 42;
  return data;
}
