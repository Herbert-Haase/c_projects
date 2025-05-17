#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#define STR_LEN 80

void create_acc(const char *user_n, char *pw);
bool transfer_money(const char *user_n, int amount);
int amount_balance(const char *user_n);
void login(const char *user_n, char *pw);

typedef struct {
  char user_n[STR_LEN + 1];
  char pw[STR_LEN + 1];
  int balance;
} acc;

static char user_n[STR_LEN + 1];
static char pw[STR_LEN + 1];
static acc logged_in_as;
