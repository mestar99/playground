
#include <malloc.h>
#include "LibWrap.h"

int main() {
  struct mallinfo beforeMalloc = mallinfo();
  printf("Bytes allocated before malloc: %d\n", beforeMalloc.uordblks);

  void* p = memAlloc(57);
  struct mallinfo afterMalloc = mallinfo();
  printf("Bytes allocated after malloc: %d\n", afterMalloc.uordblks);

  memDel(p);
  struct mallinfo afterFree = mallinfo();
  printf("Bytes allocated after free: %d\n", afterFree.uordblks);

  return 0;
}
