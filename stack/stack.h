// stack.h
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

typedef struct Stack {
  int arr[SIZE];
  int size;
  int max_size;
  void (*push)(struct Stack *, int);
  int (*pop)(struct Stack *);
  int (*peek)(struct Stack *);
  bool (*isempty)(struct Stack *);
  bool (*isfull)(struct Stack *);
  void (*clear)(struct Stack *);
  void (*print_stack)(struct Stack *);
} Stack;

void push(Stack *, int);
int pop(Stack *);
int peek(Stack *);
int size(Stack *);
bool isempty(Stack *);
bool isfull(Stack *);
Stack *init_stack(void);
void clear(Stack *);
void print_stack(Stack *);
static void stack_overflow(void);
static void stack_underflow(void);
Stack *init_stack(void);

#endif
