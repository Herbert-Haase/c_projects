#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "shell.h"


static bool iserr = false;

void print_prompt() {
  char cwd[MAX_LINE];
  if (!getcwd(cwd, MAX_LINE)) {
    perror("getcwd");
    exit(EXIT_FAILURE);
  }
  printf("%c[%dm(%s) $", 0x1B, iserr ? 31 : 97, cwd);
  printf("%c[%dm ", 0x1B, 97);
  fflush(stdout);
}

void read_input(char *line) {
  if (!fgets(line, MAX_LINE, stdin)) {
    printf("\n");
    exit(EXIT_SUCCESS);
  }
  line[strcspn(line, "\n")] = 0;
}

void parse_args(char *line, char **args) {
  int i = 0;
  char *token = strtok(line, " ");
  while (token != NULL && i < MAX_ARGS - 1) {
    args[i++] = token;
    token = strtok(NULL, " ");
  }
  args[i] = NULL;
}

void handle_cd(char **args) {
  if (!args[1]) {
    chdir(getenv("HOME"));
  } else {
    chdir(args[1]);
  }
}

void handle_exit() { exit(EXIT_SUCCESS); }

void exec_command(char **args) {
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
}

void fork_and_exec(char **args) {
  pid_t cpid = fork();
  if (cpid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  } else if (cpid == 0) {
    exec_command(args);
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
    iserr = WEXITSTATUS(wstat);
  }
}

