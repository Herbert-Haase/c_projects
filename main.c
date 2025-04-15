#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(void) {
  Queue *queue = init_queue();
  push(queue, 1);
  push(queue, 2);
  push(queue, 3);
  push(queue, 4);
  push(queue, 5);

  print_queue(queue);
  printf("pop: %d\n", pop(queue));
  printf("peek: %d\n", peek(queue));
  printf("size: %d\n", queue->size);
  pop(queue);
  puts("pop");
  print_queue(queue);
  clear(queue);
  puts("clear");
  print_queue(queue);
  printf("peek: %d\n", peek(queue));
  printf("size: %d\n", queue->size);
  printf("pop: %d\n", pop(queue));

  free(queue);
}
