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
} Queue;

Queue* init_queue(void);
bool isfull(const Queue*);
bool isempty(const Queue*);
void push(Queue*, int);
int pop(Queue*);
int peek(const Queue*);
void clear(Queue*);
void print_queue(const Queue*);

#endif
