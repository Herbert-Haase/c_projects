#include "shell.h"

int main(void) {
  puts("Welcome to mini shell");
  while (1) {
    print_prompt();

    char line[MAX_LINE];
    char *args[MAX_ARGS];

    read_input(line);
    parse_args(line, args);

    if (strcmp(args[0], "cd") == 0) {
      handle_cd(args);
      continue;
    }
    if (strcmp(args[0], "exit") == 0) {
      handle_exit();
    }

    fork_and_exec(args);
  }
  return 0;
}
