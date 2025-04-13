// stack.h
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define SIZE 32

// extern static int stack[SIZE];
// extern static int top;

void push(int);
int pop(void);
int peek(void);
int size(void);
bool isempty(void);
bool isfull(void);
void empty(void);
void print_stack(void);

#endif
