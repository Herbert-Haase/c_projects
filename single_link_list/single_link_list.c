#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OUTOFMEMORY(p)                                                         \
  if (!p) {                                                                    \
    fprintf(stderr, "out of memory: %s at %d", __FILE__, __LINE__);            \
    exit(12);                                                                  \
  }
/* macro ends here */

typedef struct List {
  int value;
  struct List *next;
} List;

typedef struct Double_list {
  int value;
  struct List *next;
  struct List *prev;
} Double_list;

void append_singlell(List *self, int value) {
  List *p = self;
  while (p->next) {
    p = p->next;
  }
  p->next = malloc(sizeof(List));
  OUTOFMEMORY(p->next)
  p->next->value = value;
}

void prepend_singlell(List *list, int value) {
  List *new_list = malloc(sizeof(List));
  OUTOFMEMORY(new_list)
  new_list->value = value;
  new_list->next = list->next;
  list->next = new_list;
}

List *init_singlell(void) {
  List *list = malloc(sizeof(List));
  OUTOFMEMORY(list)
  list->value = 0;
  return list;
}

void print_singlell(List *list) {
  printf("Single Linked List: ");
  int count = 0;
  list = list->next;
  while (list) {
    printf("%d ", list->value);
    list = list->next;
    count++;
  }
  printf("(size=%d)\n", count);
}

void clear(List *list) {
  List *p = list->next;
  while (p) {
    List *temp = p->next;
    free(p);
    p = temp;
  }
  list->next = NULL;
}

int size(List *list) {
  list = list->next;
  int len = 0;
  while (list) {
    list = list->next;
    len++;
  }
  return len;
}

void add_at(List *list, int idx, int value) {
  int len = 0;
  while (list && len < idx) {
    list = list->next;
    len++;
  }
  if (!list) return;
  List *new_list = malloc(sizeof(List));
  OUTOFMEMORY(new_list)
  new_list->next = list->next;
  new_list->value = value;
  list->next = new_list;
}

void replace(List *list, int idx, int value) {
  int len = 0;
  while (list && len < idx) {
    list = list->next;
    len++;
  }
  if (!list) return;
  List *new_list = malloc(sizeof(List));
  OUTOFMEMORY(new_list)
  new_list->value = value;
  if (list->next) {
    new_list->next = list->next->next;
    free(list->next);
  } else {
    new_list->next = NULL;
  }
  list->next = new_list;
}

int main(void) {
  List *list = init_singlell();
  append_singlell(list, 1);
  append_singlell(list, 3);
  prepend_singlell(list, 0);
  print_singlell(list);
  replace(list, 0, 0);
  add_at(list, 2, 2);
  print_singlell(list);
  clear(list);
  free(list);
}
