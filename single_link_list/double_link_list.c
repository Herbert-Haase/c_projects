// double_link_list.c
#include "double_link_list.h"
#include "link_list.h"
int doublell_create(DoubleLL **list) {
  if (!list)
    return 1;
  if (!*list) {
    *list = malloc(sizeof(DoubleLL));
    OUTOFMEMORY(list);
  }
  (*list)->head = NULL;
  (*list)->tail = NULL;
  (*list)->size = 0;
  return 0;
}

DoubleNode *doublenode_create(int value) {
  DoubleNode *node = malloc(sizeof(DoubleNode));
  OUTOFMEMORY(node);
  node->value = value;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void doublell_append(DoubleLL *list, int value) {
  if (!list)
    return;
  DoubleNode *new_node = doublenode_create(value);
  if (list->size == 0) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
}

void doublell_prepend(DoubleLL *list, int value) {
  if (!list)
    return;
  DoubleNode *new_node = doublenode_create(value);
  if (list->size == 0) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    new_node->next = list->head;
    list->head->prev = new_node;
    list->head = new_node;
  }
  list->size++;
}

void doublell_insert_at(DoubleLL *list, int idx, int value) {
  if (!list || idx >= list->size)
    return;
  DoubleNode *p;
  DoubleNode *new_node = doublenode_create(value);
  if (idx <= (list->size / 2)) {
    p = list->head;
    for (int i = 0; i < idx; i++) {
      p = p->next;
    }
    new_node->next = p;
    if (p->prev) {
      p->prev->next = new_node;
      new_node->prev = p->prev;
    } else {
      list->head = new_node;
    }
    p->prev = new_node;
  } else {
    p = list->tail;
    for (int i = 0; i < (list->size - idx) - 1; i++) {
      p = p->prev;
    }
    new_node->next = p;
    p->prev->next = new_node;
    new_node->prev = p->prev;
    p->prev = new_node;
  }
  list->size++;
}

void doublell_replace_at(DoubleLL *list, int idx, int value) {
  if (!list || idx >= list->size)
    return;
  DoubleNode *p;
  if (idx <= (list->size / 2)) {
    p = list->head;
    for (int i = 0; i < idx; i++) {
      p = p->next;
    }
    p->value = value;
  } else {
    p = list->tail;
    for (int i = 0; i <= (list->size - idx); i++) {
      p = p->prev;
    }
    p->value = value;
  }
}

void doublell_print(const DoubleLL *list) {
  printf("Double Linked List: front ");
  DoubleNode *p = list->head;
  while (p) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("(size=%d)\n", list->size);
  printf("Double Linked List: back ");
  p = list->tail;
  while (p) {
    printf("%d ", p->value);
    p = p->prev;
  }
  printf("(size=%d)\n", list->size);
}

void doublell_clear(DoubleLL *list) {
  if (!list)
    return;
  DoubleNode *p = list->head;
  while (p) {
    DoubleNode *next = p->next;
    free(p);
    p = next;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

