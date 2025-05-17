#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 100
#define MAX_LINE 1024

int main(void) {
  puts("Welcome to mini shell");
  while (1) {
    printf("$ ");
    fflush(stdout);

    pid_t cpid = fork();
    if (cpid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (cpid == 0) {
      char line[MAX_LINE];
      char *args[MAX_ARGS];
      int i = 0;
      fflush(stdout);
      if (!fgets(line, sizeof(line), stdin)) {
        perror("fgets");
        _exit(EXIT_FAILURE);
      }
      line[strcspn(line, "\n")] = 0;

      char *token = strtok(line, " ");
      while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
      }
      args[i] = NULL;

      execvp(args[0], args);
      perror("execvp");
      exit(EXIT_FAILURE);

    } else {
      int wstat;
      pid_t w = wait(&wstat);
      if (w == -1) {
        perror("wait");
        exit(EXIT_FAILURE);
      }
    }
  }
  return 0;
}
