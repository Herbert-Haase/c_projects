#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(void) {
  Queue *queue = init_queue();
  queue->push(queue, 1);
  queue->push(queue, 2);
  queue->push(queue, 3);
  queue->push(queue, 4);
  queue->push(queue, 5);

  queue->print_queue(queue);
  printf("pop: %d\n", queue->pop(queue));
  printf("peek: %d\n", queue->peek(queue));
  printf("size: %d\n", queue->size);
  queue->pop(queue);
  puts("pop");
  queue->print_queue(queue);
  queue->clear(queue);
  puts("clear");
  queue->print_queue(queue);
  printf("peek: %d\n", queue->peek(queue));
  printf("size: %d\n", queue->size);
  printf("pop: %d\n", queue->pop(queue));

  free(queue);
}
