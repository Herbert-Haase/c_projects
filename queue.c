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

void queue_overflow(void) {
  fprintf(stderr, "queue overflow: %s at %d\n", __FILE__, __LINE__);
  exit(1);
}

void queue_underflow(void) {
  fprintf(stderr, "queue underflow: %s at %d\n", __FILE__, __LINE__);
  exit(1);
}

Queue *init_queue(void) {
  Queue *q = malloc(sizeof(Queue));
  if (!q) {
    fprintf(stderr, "out of memory: %s at %d\n", __FILE__, __LINE__);
    exit(12);
  }
  q->size = 0;
  q->max_size = N;
  q->front = 0;
  q->back = N - 1;
  return q;
}

bool isfull(const Queue *self) { return self->size == self->max_size; }

bool isempty(const Queue *self) { return self->size == 0; }

void push(Queue *self, int value) {
  if (isfull(self))
    queue_overflow();
  self->back = (self->back + 1) % self->max_size;
  self->data[self->back] = value;
  self->size++;
}

int pop(Queue *self) {
  if (isempty(self))
    queue_underflow();
  int x = self->data[self->front];
  self->front = (self->front + 1) % self->max_size;
  self->size--;
  return x;
}

int peek(const Queue *self) {
  if (isempty(self))
    return 0;
  return self->data[self->front];
}

void clear(Queue *self) {
  self->size = 0;
  self->front = 0;
  self->back = N - 1;
}

void print_queue(const Queue *self) {
  printf("Queue (size=%d): ", self->size);
  for (int i = 0, j = self->back; i < self->size; i++, j--) {
    if (j < 0)
      j = self->max_size - 1;
    printf("%d ", self->data[j]);
  }
  printf("\n");
}
