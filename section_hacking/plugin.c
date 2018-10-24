
#include <stdio.h>
#include "section_hacking.h"

static void in_equotes( char const * txt)
{
  printf("'%s'\n", txt);
}

REGISTER_FORMATTER(in_equotes);

static void in_arrows( char const * txt)
{
  printf("-->>>%s<<<---\n", txt);
}

REGISTER_FORMATTER(in_arrows);

static void in_pizza( char const * txt)
{
  printf(":pizza:%s:pizza:\n", txt);
}

REGISTER_FORMATTER(in_pizza);
