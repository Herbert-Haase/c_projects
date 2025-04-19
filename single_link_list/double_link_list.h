// double_link_list.h
#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLL {
  struct DoubleNode *head;
  struct DoubleNode *tail;
  int size;
} DoubleLL;

typedef struct DoubleNode {
  int value;
  struct DoubleNode *next;
  struct DoubleNode *prev;
} DoubleNode;

int doublell_create(DoubleLL **list);
void doublell_append(DoubleLL *list, int value);
void doublell_prepend(DoubleLL *list, int value);
void doublell_insert_at(DoubleLL *list, int idx, int value);
void doublell_replace_at(DoubleLL *list, int idx, int value);
void doublell_print(const DoubleLL *list);
void doublell_clear(DoubleLL *list);

#endif
