
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void * th_fn(void * arg)
{
  char *dso_name = (char *) arg;
  void * handle = dlopen( dso_name, RTLD_NOW | RTLD_GLOBAL );

  if(handle == NULL) {
    fprintf( stderr, "Didn't open lib: %s: %s\n",
	     dso_name, dlerror());
    return (void *) -1;
  }

  dlclose( handle );
  return (void *) 0;
}

int main(int argc, char *argv[])
{
  char * dso_name;
  pthread_t child_th;

  if(argc == 1) {
    printf("dlopen_test DSO_TO_LOAD\n");
    exit(-1);
  }

  dso_name = argv[1];
  pthread_create( &child_th, NULL, th_fn, dso_name);
  if(fork() == 0) {
    th_fn(dso_name);
    exit(0);
  }

  pthread_join(child_th, NULL);
  wait(NULL);
  return 0;
}
