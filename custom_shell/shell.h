#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 100
#define MAX_LINE 1024

#include <string.h>
#include <stdio.h>

void print_prompt(void);
void read_input(char *line);
void parse_args(char *line, char **args);
void handle_cd(char **args);
void handle_exit(void);
void exec_command(char **args);
void fork_and_exec(char **args);

#endif
