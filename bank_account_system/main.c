#include "functions.h"

int main(void) {
  while (true) {
    puts("Welcome to Viva Bank, the bank system of your choice.");
    puts("Would you like to: \n \
    (a) create a new account\n \
    (t) transfer money to your account\n \
    (c) check the balance of your account\n \
    (l) login using username and password \n \
    (q) exit programm");
    printf("Your order please: ");

    int order = getchar();
    while ((getchar()) != '\n')
      ;
    if (order == EOF)
      exit(1);
    switch (order) {
    case 'a':
      puts("(a) create a new account");
      printf("Username: \n");
      scanf("%s", user_n);
      printf("Password: \n");
      scanf("%s", pw);
      create_acc(user_n, pw);
      break;
    case 't':
      puts("(t) transfer money from your account");
      if (*logged_in_as.user_n != '\0') {
        printf("user name: \n");
        scanf("%s", user_n);
        printf("amount: \n");
        int amount;
        scanf("%d", &amount);
        if (transfer_money(user_n, amount)) {
          if (transfer_money(logged_in_as.user_n, -amount)) {
            puts("money transferred successfully");
          } else {
              transfer_money(user_n, -amount);
            }
        }
      } else {
        puts("please login first");
      }
      break;
    case 'c':
      puts("(c) check the balance of your account");
      if (*user_n) {
        int balance;
        balance = amount_balance(user_n);
        printf("Your balance is: %d\n", balance);
      } else {
        puts("please login first");
      }
      break;
    case 'l':
      puts("(l) login using username and password");
      printf("Username: \n");
      scanf("%s", user_n);
      printf("Password: \n");
      scanf("%s", pw);
      login(user_n, pw);
      break;
    case 'q':
      puts("(q) exit programm");
      puts("See you soon");
      exit(EXIT_SUCCESS);
      break;
    default:
      printf("Unknown command: '%c'\n", (char)order);
    }
    while ((getchar()) != '\n')
      ;
  }
}

