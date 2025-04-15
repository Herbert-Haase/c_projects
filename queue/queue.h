// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define N 32

typedef struct Queue {
  int data[N];
  int size;
  int max_size;
  int front;
  int back;
  bool (*isfull)(const struct Queue*);
  bool (*isempty)(const struct Queue*);
  void (*push)(struct Queue*, int);
  int (*pop)(struct Queue*);
  int (*peek)(const struct Queue*);
  void (*clear)(struct Queue*);
  void (*print_queue)(const struct Queue*);
} Queue;

Queue* init_queue(void);

#endif
