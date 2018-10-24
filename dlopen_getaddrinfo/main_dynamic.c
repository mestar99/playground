
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "libA.h"

int main()
{
  printf("Calling something()\n");

  void *handle;
  void (*something)();
  char *error;
  
  handle = dlopen("libA.so", RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
  if( !handle ) {
    fprintf( stderr, "%s\n", dlerror());
    exit(EXIT_FAILURE);
  }
  
  dlerror();
  
  something = (void (*)()) dlsym( handle, "something" );
  
  error = dlerror();
  if(error != NULL) {
    fprintf( stderr, "%s\n", error);
    exit(EXIT_FAILURE);
  }
  
  (*something)();
  dlclose(handle);
  
  printf("Finished something()\n");

  return 0;
}
