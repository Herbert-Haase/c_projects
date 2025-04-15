#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void) {
  Stack *stack = init_stack();
  stack->push(stack, 1);
  stack->push(stack, 2);
  stack->push(stack, 3);
  stack->push(stack, 4);
  stack->push(stack, 5);

  stack->print_stack(stack);
  printf("pop: %d\n", stack->pop(stack));
  printf("peek: %d\n", stack->peek(stack));
  printf("size: %d\n", stack->size);
  stack->pop(stack);
  puts("pop");
  stack->print_stack(stack);
  stack->clear(stack);
  puts("clear");
  stack->print_stack(stack);
  printf("peek: %d\n", stack->peek(stack));
  printf("size: %d\n", stack->size);
  printf("pop: %d\n", stack->pop(stack));

  free(stack);
}
