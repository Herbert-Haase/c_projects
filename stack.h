// stack.h
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define SIZE 32

typedef struct {
  int arr[SIZE];
  int size;
} Stack;

void push(Stack*, int);
int pop(Stack*);
int peek(Stack*);
int size(Stack*);
bool isempty(Stack*);
bool isfull(Stack*);
Stack* init_stack(void);
void empty(Stack*);
void print_stack(Stack*);


#endif
