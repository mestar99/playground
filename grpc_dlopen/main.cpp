
#include <cstdio>
#include <cstdlib>
#include <dlfcn.h>

extern "C" {
  void initLibrary();
}

int main()
{
  void *handle;
  
  handle = dlopen("libA.so", RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
  if( !handle ) {
    fprintf(stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }
  
  dlclose(handle);

  //initLibrary();

  return 0;
}
