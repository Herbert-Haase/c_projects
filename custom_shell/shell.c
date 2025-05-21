#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_ARGS 100
#define MAX_LINE 1024

static bool iserr = false;

int main(void) {
  puts("Welcome to mini shell");
  while (1) {
    char cwd[MAX_LINE];
    if (!getcwd(cwd, MAX_LINE)) {
      perror("getcwd");
      exit(EXIT_FAILURE);
    }
    printf("%c[%dm(%s) $", 0x1B, iserr ? 31 : 97, cwd);
    printf("%c[%dm ", 0x1B, 97);
    fflush(stdout);
    char line[MAX_LINE];
    char *args[MAX_ARGS];
    int i = 0;
    fflush(stdout);
    if (!fgets(line, sizeof(line), stdin)) {
      printf("\n"); // makes ctrl+d and exit look similar
      exit(EXIT_SUCCESS);
    }
    line[strcspn(line, "\n")] = 0;

    char *token = strtok(line, " ");
    while (token != NULL && i < MAX_ARGS - 1) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (strcmp(args[0], "cd") == 0) {
      if (!args[1]) {
        chdir("$HOME");
      } else {
        chdir(args[1]);
      }
      continue;
    }
    if (strcmp(args[0], "exit") == 0) {
      exit(EXIT_SUCCESS);
    }

    pid_t cpid = fork();
    if (cpid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (cpid == 0) {
      if (strcmp(args[0], "!") == 0) {
        if (strcmp(args[1], "true"))
          _exit(EXIT_FAILURE);
        else if (strcmp(args[1], "false"))
          _exit(EXIT_SUCCESS);
      }
      char *env_p = getenv("PATH");
      char *token = strtok(env_p, ":");
      while (token) {
        char abs_p[MAX_ARGS + strlen(token)];
        strcpy(abs_p, token);
        strcat(abs_p, "/");
        strcat(abs_p, args[0]);
        execv(abs_p, args);
        token = strtok(NULL, ":");
      }

      fprintf(stderr, "%s: no such command\n", args[0]);
      _exit(EXIT_FAILURE);

    } else {
      int wstat;
      pid_t w = wait(&wstat);
      if (w == -1) {
        perror("wait");
        exit(EXIT_FAILURE);
      }
      char cwd[MAX_LINE];
      if (!getcwd(cwd, MAX_LINE)) {
        perror("getcwd");
        exit(EXIT_FAILURE);
      }
      if (WEXITSTATUS(wstat)) {
        iserr = true;
      } else
        iserr = false;
    }
  }
  return 0;
}
