// single_link_list.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OUTOFMEMORY(p)                                                         \
  if (!(p)) {                                                                  \
    fprintf(stderr, "out of memory: %s at %d", __FILE__, __LINE__);            \
    exit(12);                                                                  \
  }
/* macro ends here */

typedef struct SingleLL {
  int value;
  struct SingleLL *next;
} SingleLL;

SingleLL *singlell_create(int value) {
  SingleLL *node = malloc(sizeof(SingleLL));
  OUTOFMEMORY(node);
  node->value = value;
  node->next = NULL;
  return node;
}

void singlell_append(SingleLL **head, int value) {
  if (!head)
    return;
  SingleLL *new_node = singlell_create(value);
  if (!*head) {
    *head = new_node;
    return;
  }
  SingleLL *p = *head;
  while (p->next)
    p = p->next;
  p->next = new_node;
}

void singlell_prepend(SingleLL **head, int value) {
  if (!head)
    return;
  SingleLL *new_node = singlell_create(value);
  new_node->next = *head;
  *head = new_node;
}

void singlell_insert_at(SingleLL **head, int idx, int value) {
  if (!head || idx < 0)
    return;
  if (idx == 0) {
    singlell_prepend(head, value);
    return;
  }
  SingleLL *p = *head;
  for (int i = 0; p && i < idx - 1; i++)
    p = p->next;
  if (!p)
    return;
  SingleLL *new_node = singlell_create(value);
  new_node->next = p->next;
  p->next = new_node;
}

void singlell_replace_at(SingleLL **head, int idx, int value) {
  if (!head || idx < 0)
    return;
  SingleLL *p = *head;
  for (int i = 0; p && i < idx; i++)
    p = p->next;
  if (!p)
    return;
  p->value = value;
}

void singlell_print(const SingleLL *head) {
  printf("Single Linked List: ");
  int count = 0;
  while (head) {
    printf("%d ", head->value);
    head = head->next;
    count++;
  }
  printf("(size=%d)\n", count);
}

int singlell_size(const SingleLL *head) {
  int len = 0;
  while (head) {
    len++;
    head = head->next;
  }
  return len;
}

void singlell_clear(SingleLL **head) {
  if (!head)
    return;
  SingleLL *p = *head;
  while (p) {
    SingleLL *next = p->next;
    free(p);
    p = next;
  }
  *head = NULL;
}

int main(void) {
  SingleLL *list = NULL;
  singlell_append(&list, 1);
  singlell_append(&list, 3);
  singlell_prepend(&list, 0);
  singlell_print(list);

  singlell_replace_at(&list, 0, 0);
  singlell_insert_at(&list, 2, 2);
  singlell_print(list);

  singlell_clear(&list);
  return 0;
}
