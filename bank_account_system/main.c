#!/ usr / bin / tcc - run

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 80

void create_acc(char *user_n, char *pw);
void transfer_money(int amount);
int amount_balance(char *user_n);
void login(char *user_n, char *pw);

typedef struct {
  char user_n[STR_LEN + 1];
  char pw[STR_LEN + 1];
  int balance;
} acc;

static double balance;
static char user_n[STR_LEN + 1];
static char pw[STR_LEN + 1];

int main(void) {
  puts("Welcome to Viva Bank, the bank system of your choice.");
  puts("Would you like to: \n \
    (a) create a new account\n \
    (t) transfer money to your account\n \
    (c) check the balance of your account\n \
    (l) login using username and password \n \
    (q) exit programm");
  printf("Your order please: ");

  char order;
  scanf("%c", &order);
  switch (order) {
  case 'a':
    printf("Username: ");
    scanf("%s", user_n);
    printf("\nPassword: ");
    scanf("%s", pw);
    create_acc(user_n, pw);
    break;
  case 't':
    if (*user_n) {
      printf("amount: ");
      int amount;
      scanf("%d", &amount);
      transfer_money(amount);
    } else {
      puts("please login first");
    }
    break;
  case 'c':
    if (*user_n) {
      balance = amount_balance(user_n);
      printf("Your balance: %g", balance);
    } else {
      puts("please login first");
    }
    break;
  case 'l':
    printf("Username: ");
    scanf("%s", user_n);
    puts("");
    printf("Password: ");
    scanf("%s", pw);
    login(user_n, pw);
    break;
  case 'q':
    puts("See you soon");
    exit(EXIT_SUCCESS);
    break;
  }
}

int create_acc(char *user_n, char *pw) {
  char *account_file = "account_data.txt";
  FILE *fp = fopen(account_file, "a+");
  if (fp == NULL) {
    fprintf(stderr, "data unwritable\n");
    exit(EXIT_FAILURE);
  }
  acc user = {.user_n = *user_n, .pw = *pw, .balance = 0};
  if (fwrite(&user, sizeof(acc), 1, fp)) {
    fprintf(stderr, "data unwritable\n");
    exit(EXIT_FAILURE);
  }
  fclose(fp);
}

void transfer_money(int amount) {
  char *account_file = "account_data.txt";
  FILE *fp = fopen(account_file, "a");
  if (fp == NULL) {
    fprintf(stderr, "data unwritable\n");
    exit(EXIT_FAILURE);
  }
  acc user = {.user_n = *user_n, .pw = *pw, .balance = 0};
  if (fwrite(&user, sizeof(acc), 1, fp)) {
    fprintf(stderr, "data unwritable\n");
    exit(EXIT_FAILURE);
  }
  fclose(fp);
}
int amount_balance(char *user_n) {}
void login(char *user_n, char *pw) {}
