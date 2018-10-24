
#include "hello.pb.h"
#include <fstream>
#include <iostream>

int main()
{
  std::fstream fo("./hello.data", std::ios::binary | std::ios::out);
  hello p1, p2, p3;
  p1.set_f1(1);
  p1.set_f2(2);
  p2.set_f1(3);
  p2.set_f2(4);
  p3.set_f1(5);
  p3.set_f2(6);
  p1.SerializeToOstream(&fo);
  p2.SerializeToOstream(&fo);
  p3.SerializeToOstream(&fo);
  fo.close();

  std::fstream fi("./hello.data", std::ios::binary | std::ios::in);
  hello pi;
  pi.ParseFromIstream(&fi);
  std::cout << pi.f1() << " " << pi.f2() << std::endl;

  return 0;
}
