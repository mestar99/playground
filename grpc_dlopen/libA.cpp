
#include <grpc++/grpc++.h>
#include <memory>
#include <cstdio>

extern "C" {
  
  void initLibrary() __attribute__((constructor));

  void initLibrary()
  {
    printf("Library Init\n");

    std::shared_ptr< grpc::ChannelCredentials > creds = grpc::GoogleDefaultCredentials();

    printf("Library Init Finished\n");
  }
}
