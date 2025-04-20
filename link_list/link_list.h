#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <stdio.h>
#include <stdlib.h>

#define OUTOFMEMORY(p)                                                         \
  do {                                                                         \
    if (!(p)) {                                                                \
      fprintf(stderr, "out of memory: %s at %d", __FILE__, __LINE__);          \
      exit(12);                                                                \
    }                                                                          \
  } while (0)

#define list_append(list, value)                                               \
  _Generic((list),                                                             \
      SingleLL * *: singlell_append,                                           \
      DoubleLL *: doublell_append)(list, value)
#define list_prepend(list, value)                                              \
  _Generic((list),                                                             \
      SingleLL * *: singlell_prepend,                                          \
      DoubleLL *: doublell_prepend)(list, value)
#define list_insert_at(list, idx, value)                                       \
  _Generic((list),                                                             \
      SingleLL * *: singlell_insert_at,                                        \
      DoubleLL *: doublell_insert_at)(list, idx, value)
#define list_replace_at(list, idx, value)                                      \
  _Generic((list),                                                             \
      SingleLL * *: singlell_replace_at,                                       \
      DoubleLL *: doublell_replace_at)(list, idx, value)
#define list_print(list)                                                       \
  _Generic((list), SingleLL *: singlell_print, DoubleLL *: doublell_print)(list)
#define list_clear(list)                                                       \
  _Generic((list), SingleLL * *: singlell_clear, DoubleLL *: doublell_clear)(  \
      list)
/* macros ends here */

#endif
