#include <stdio.h>
#include "stack.h"

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
