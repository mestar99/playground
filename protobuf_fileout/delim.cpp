
#include "hello.pb.h"
#include <fstream>
#include <iostream>

#include <google/protobuf/util/delimited_message_util.h>

int main()
{
  std::fstream fo("./hello_delim.data", std::ios::binary | std::ios::out);
  hello p1, p2, p3;
  p1.set_f1(1);
  p1.set_f2(2);
  p2.set_f1(3);
  p2.set_f2(4);
  p3.set_f1(5);
  p3.set_f2(6);

  google::protobuf::util::SerializeDelimitedToOstream( p1, &fo );
  google::protobuf::util::SerializeDelimitedToOstream( p2, &fo );
  google::protobuf::util::SerializeDelimitedToOstream( p3, &fo );

  fo.close();

  std::fstream fi("./hello_delim.data", std::ios::binary | std::ios::in);
  google::protobuf::io::IstreamInputStream is( &fi );
  hello pi;
  bool clean_eof;
  google::protobuf::util::ParseDelimitedFromZeroCopyStream( &pi, &is, &clean_eof );
  std::cout << pi.f1() << " " << pi.f2() << std::endl;

  return 0;
}
