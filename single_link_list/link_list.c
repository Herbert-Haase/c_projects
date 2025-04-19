// link_list.c
#include "link_list.h"
#include "double_link_list.h"
#include "single_link_list.h"

int main(void) {
  SingleLL *list = NULL;
  list_append(&list, 1);
  list_prepend(&list, 0);
  list_replace_at(&list, 0, 0);
  list_insert_at(&list, 2, 2);
  list_print(list);
  list_clear(&list);
  free(list);


  DoubleLL *dlist = NULL;
  doublell_create(&dlist);
  list_append(dlist, 0);
  list_append(dlist, 1);
  list_append(dlist, 2);
  list_print(dlist);
  list_clear(dlist);
  free(dlist);
  return 0;
}
