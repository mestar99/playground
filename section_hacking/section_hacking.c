
#include <stdio.h>
#include "section_hacking.h"

static void in_quotes(char const * txt)
{
  printf("\"%s\"\n", txt);
}

REGISTER_FORMATTER(in_quotes);

extern struct formatter_info __start_my_formatters;
extern struct formatter_info __stop_my_formatters;

static void format_all(char const * txt)
{
  struct formatter_info * iter = &__start_my_formatters;

  for( ; iter < &__stop_my_formatters; ++iter) {
    printf("Formatting with %s: ", iter->name);
    iter->fn(txt);
  }
}

int main( int argc, char * argv[])
{
  printf("Formatters are sitting from 0x%p to 0x%p\n",
         (void *) &__start_my_formatters,
         (void *) &__stop_my_formatters);

  format_all("My Formatted Text");

  return 0;
}
