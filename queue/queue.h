// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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


Queue *init_queue(void);
bool isfull(const Queue *);
bool isempty(const Queue *);
void push(Queue *, int);
int pop(Queue *);
int peek(const Queue *);
void clear(Queue *);
void print_queue(const Queue *);
static void queue_overflow(void);
static void queue_underflow(void);
Queue* init_queue(void);

#endif
