
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
  char ** ptr = environ;

  while( *ptr ) {
    
    printf("%s\n",*ptr);

    ptr++;
  }

  printf("------------\n");
  
  ptr = envp;

  while( *ptr) {
    printf("%s\n",*ptr);

    ptr++;
  }

  return 0;
}
