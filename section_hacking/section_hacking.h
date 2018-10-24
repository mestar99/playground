
#ifndef __SECTION_HACKING_H__
#define __SECTION_HACKING_H__

typedef void (*formatter_fn_t)(char const *);

struct formatter_info {
  formatter_fn_t fn;
  char * name;
};

#define REGISTER_FORMATTER(func)                        \
  static struct formatter_info __formatter_ ## func     \
  __attribute((__section__("my_formatters")))           \
  __attribute((__used__)) = {                           \
    .fn = func,                                         \
    .name = #func,                                      \
  }

#endif
