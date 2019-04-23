#define _GNU_SOURCE
#include <dlfcn.h>
#include "LibWrap.h"

static void * malloc(size_t s) {
  // Wrapper for standard library's 'malloc'
  // The 'static' keyword forces all calls to malloc() in this file to resolve
  // to this functions

  void* (*origMalloc)(size_t) = dlsym(RTLD_NEXT,"malloc");
  return origMalloc(s);
}

static void free(void* p) {
  // Wrapper for standard library's 'free'
  // The 'static' keyword forces all calls to free() in this file to resolve
  // to this function
  void (*origFree)(void*) = dlsym(RTLD_NEXT,"free");
  origFree(p);
}

void* memAlloc(size_t s) {
  return malloc(s);
}

void memDel(void* p) {
  free(p);
}
