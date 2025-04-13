// stack
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

static int stack[SIZE];
static int top = 0;

void push(int);
int pop(void);
int peek(void);
int size(void);
bool isempty(void);
bool isfull(void);
void empty(void);
static void stack_overflow(void);
static void stack_underflow(void);
static void print_stack(void);

int main(void) {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  print_stack();
  printf("pop: %d\n", pop());
  printf("peek: %d\n", peek());
  printf("size: %d\n", size());
  pop();
  puts("pop\n");
  print_stack();
  empty();
  print_stack();
  printf("peek: %d\n", peek());
  printf("size: %d\n", size());
  printf("pop: %d\n", pop());
}

void print_stack(void) {
  printf("Stack (top=%d): ", top);
  for (int i = 0; i < top; i++) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

void stack_overflow(void) {
  printf("stack overflow: %s at %d", __FILE__, __LINE__);
  exit(1);
}

void stack_underflow(void) {
  printf("stack underflow: %s at %d", __FILE__, __LINE__);
  exit(1);
}

int size(void) { return top; }

bool isfull(void) { return top == SIZE; }

bool isempty(void) { return top == 0; }

void push(int element) {
  if (isfull()) {
    stack_overflow();
  } else
    stack[top++] = element;
}

int pop(void) {
  if (isempty()) {
    stack_underflow();
  }
  return stack[--top];
}

int peek(void) {
  if (top == 0)
    return 0;
  return stack[top - 1];
}

void empty(void) { top = 0; }
