
#include <iostream>
#include <string>
#include <dlfcn.h>

void print(std::string const & val)
{
  std::cout << val << std::endl;
}

void sharedprint(std::string const & library)
{
  void *handle;
  handle = dlopen(library.c_str(), RTLD_LAZY);
  if( !handle ) {
    std::cerr << dlerror() << std::endl;
    return;
  }

  dlerror();

  void (*remote_print)(char const *); 
  *(void**)(&remote_print) = dlsym(handle, "load");

  char * error = dlerror();
  if(error != NULL) {
    std::cerr << error << std::endl;
    return ;
  }

  std::string output{ "Goodbye " + library + "!" };

  remote_print(output.c_str());
  dlclose(handle);
}

int main()
{
  print("Hello world!");

  sharedprint("libshared.so.1");
  sharedprint("libshared.so.2");
  sharedprint("libshared.so.3");
  sharedprint("libshared.so.4");
  sharedprint("libshared.so.5");

  return 0;
}
