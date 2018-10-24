
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

static void * thread_func(void * args)
{
  // perform a getaddrinfo
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int s;

  memset( &hints, 0, sizeof(struct addrinfo) );
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = 0;
  hints.ai_protocol = 0;

  s = getaddrinfo("portquiz.net","80", &hints, &result);
  if( s != 0 ) {
    fprintf( stderr, "getaddrinfo: %s\n", gai_strerror(s));
    return;
  }

  for( rp = result; rp != NULL; rp = rp->ai_next ) {
    printf( "%d %d %d\n", rp->ai_family, rp->ai_socktype, rp->ai_protocol);
  }

  freeaddrinfo(result);
}

static void load()
{
  int s;
  pthread_t thread_id;
  void *res;

  s = pthread_create( &thread_id, NULL, &thread_func, NULL);

  s = pthread_join( thread_id, &res);
}

void something()
{
  printf("I'm doing stuff!\n");
}

static void con() __attribute__((constructor));

void con() {
  printf("I'm a constructor\n");

  //load();
  thread_func(NULL);
}
