#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void) {
  Stack stack = init_stack();
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);

  print_stack(stack);
  printf("pop: %d\n", pop(stack));
  printf("peek: %d\n",peek(stack));
  printf("size: %d\n",size(stack));
  pop(stack);
  puts("pop");
  print_stack(stack);
  clear(stack);
  puts("clear");
  print_stack(stack);
  printf("peek: %d\n",peek(stack));
  printf("size: %d\n",size(stack));
  printf("pop: %d\n", pop(stack));

  free(stack);
}
