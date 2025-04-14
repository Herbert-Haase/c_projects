// stack.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

//#define SIZE 32

void push(Stack*, int);
int pop(Stack*);
int peek(Stack*);
int size(Stack*);
bool isempty(Stack*);
bool isfull(Stack*);
void initialize(Stack*);
void empty(Stack*);
void print_stack(Stack*);
static void stack_overflow(void);
static void stack_underflow(void);


void print_stack(Stack *stack) {
  printf("Stack (size=%d): ", stack->size);
  for (int i = 0; i < stack->size; i++) {
    printf("%d ", stack->arr[i]);
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

void initialize(Stack *stack) {
  stack->size = 0;
}

bool isempty(Stack *stack) {
  return stack->size == 0;
}

bool isfull(Stack *stack) {
  return stack->size == SIZE;
}

void push(Stack *stack, int value) {
  if(isfull(stack)) stack_overflow();
  stack->arr[(stack->size)++] = value;
}

int pop(Stack *stack) {
  if(isempty(stack)) stack_underflow();
  return stack->arr[--(stack->size)];
}

int peek(Stack *stack) {
  return stack->arr[stack->size];
}

int size(Stack *stack) {
  return stack->size;
}

void empty(Stack *stack) {
  initialize(stack);
}







