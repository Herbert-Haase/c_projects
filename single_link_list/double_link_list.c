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

SingleLL *singlell_create(int value) {
  SingleLL *node = malloc(sizeof(SingleLL));
  OUTOFMEMORY(node);
  node->value = value;
  node->next = NULL;
  return node;
}

DoubleNode *doublell_create(int value) {
  DoubleNode *node = malloc(sizeof(DoubleNode));
  OUTOFMEMORY(node);
  node->value = value;
  node->next = NULL;
  node->prev = NULL;
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

void doublell_append(DoubleLL *list, int value) {
  if (!list)
    return;
  DoubleNode *new_node = doublell_create(value);
  if (list->size == 0) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    new_node->prev = list->tail;
    list->tail->next = new_node;
  }
  list->size++;
}

void singlell_prepend(SingleLL **head, int value) {
  if (!head)
    return;
  SingleLL *new_node = singlell_create(value);
  new_node->next = *head;
  *head = new_node;
}

void doublell_prepend(DoubleLL *list, int value) {
  if (!list)
    return;
  DoubleNode *new_node = doublell_create(value);
  if (list->size == 0) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    new_node->next = list->head;
    list->head = new_node;
  }
  list->size++;
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

void doublell_insert_at(DoubleLL *list, int idx, int value) {
  if (!list || idx >= list->size)
    return;
  DoubleNode *p;
  DoubleNode *new_node = doublell_create(value);
  if (idx < (list->size / 2)) {
    p = list->head;
    for (int i = 0; i < idx - 1; i++) {
      p = p->next;
    }
    new_node->next = p->next;
    p->next->prev = new_node;
    p->next = new_node;
    new_node->prev = p;
  } else {
    p = list->tail;
    for (int i = 0; i < (list->size - idx) - 1; i++) {
      p = p->prev;
    }
    new_node->next = p->next;
    p->next->prev = new_node;
    p->next = new_node;
    new_node->prev = p;
  }
  list->size++;
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

void doublell_replace_at(DoubleLL *list, int idx, int value) {
  if (!list || idx >= list->size)
    return;
  DoubleNode *p;
  if (idx < (list->size / 2)) {
    p = list->head;
    for (int i = 0; i < idx; i++) {
      p = p->next;
    }
    p->value = value;
  } else {
    p = list->tail;
    for (int i = 0; i < (list->size - idx); i++) {
      p = p->prev;
    }
    p->value = value;
  }
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

void doublell_print(const DoubleLL *list) {
  printf("Double Linked List: front");
  DoubleNode* p = list->head;
  while (p) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("(size=%d)\n", list->size);
  printf("Double Linked List: back");
  p = list->tail;
  while (p) {
    printf("%d ", p->value);
    p = p->prev;
  }
  printf("(size=%d)\n", list->size);
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

void doublell_clear(DoubleLL *list){
  if(!list) return;
  DoubleNode *p = list->head;
  while(p) {
    DoubleNode* next = p->next;
    free(p);
    p = next;
  }
  list->head = NULL;
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
