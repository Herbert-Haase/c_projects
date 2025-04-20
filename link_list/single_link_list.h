// single_link_list.h
#ifndef SINGLE_LINK_LIST_H
#define SINGLE_LINK_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLL {
  int value;
  struct SingleLL *next;
} SingleLL;


void singlell_append(SingleLL **head, int value);
void singlell_prepend(SingleLL **head, int value);
void singlell_insert_at(SingleLL **head, int idx, int value);
void singlell_replace_at(SingleLL **head, int idx, int value);
void singlell_print(const SingleLL *head);
int singlell_size(const SingleLL *head);
void singlell_clear(SingleLL **head);


#endif
