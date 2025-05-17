#include "functions.h"

/**
 * Creates an User account and logs if no user with that user name exist
 * already.
 *
 */
void create_acc(const char *user_n, char *pw) {
  const char in_n[] = "account_data.dat";
  FILE *in = fopen(in_n, "ab+");
  if (in == NULL) {
    fprintf(stderr, "data unwritable: %s at %d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  acc old_user;
  while (true) {
    size_t ret_code = fread(&old_user, sizeof(acc), 1, in);
    if (ret_code) {
      if (!strcmp(old_user.user_n, user_n)) {
        puts("User already exists\n");
        return;
      }
    } else {
      if (feof(in)) {
        break;
      } else if (ferror(in)) {
        printf("Error reading %s\n", in_n);
        exit(EXIT_FAILURE);
      }
    }
  }
  acc new_user;
  strcpy(new_user.user_n, user_n);
  strcpy(new_user.pw, pw);
  new_user.balance = 0;
  if (!fwrite(&new_user, sizeof(acc), 1, in)) {
    fprintf(stderr, "data unwritable: %s at %d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  strcpy(logged_in_as.user_n, new_user.user_n);
  strcpy(logged_in_as.pw, new_user.pw);
  logged_in_as.balance = new_user.balance;
  puts("User created successfully\n");
  fclose(in);
}

/**
 * transfers money from logged in user to another user.
 * negative balances are allowed.
 *
 */
bool transfer_money(const char *user_n, int amount) {
  const char in_n[] = "account_data.dat";
  FILE *in = fopen(in_n, "rb+");
  if (in == NULL) {
    fprintf(stderr, "data unwritable: %s at %d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }

  acc old_user;
  while (fread(&old_user, sizeof(acc), 1, in) == 1) {
    if (strcmp(old_user.user_n, user_n) == 0) {
      old_user.balance += amount;
      if (fseek(in, -((long)sizeof(acc)), SEEK_CUR) != 0) {
        fprintf(stderr, "fseek failed at: %s at %d\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
      }
      if (fwrite(&old_user, sizeof(acc), 1, in) != 1) {
        fprintf(stderr, "fseek failed at: %s at %d\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
      }
      if (strcmp(user_n, logged_in_as.user_n) == 0) {
        logged_in_as.balance = old_user.balance;
      }

      fclose(in);
      return true;
    }
  }
  puts("Receiver not found");
  fclose(in);
  return false;
}

/**
 * Gives an logged in user back how high his balance is
 *
 *
 */
int amount_balance(const char *user_n) {
  if (*logged_in_as.user_n == '\0') {
    puts("Please login first");
    return 0;
  }
  const char in_n[] = "account_data.dat";
  FILE *in = fopen(in_n, "rb");
  if (in == NULL) {
    fprintf(stderr, "data unreadable: %s at %d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  acc old_user;
  while (fread(&old_user, sizeof(acc), 1, in) == 1) {
    if (strcmp(old_user.user_n, user_n) == 0) {
      fclose(in);
      return old_user.balance;
    }
  }
  fclose(in);
  return 0;
}
/*
 * logs the user in, if the data file was already created and
 * an account was already made
 *
 *
 */
void login(const char *user_n, char *pw) {
  const char in_n[] = "account_data.dat";
  FILE *in = fopen(in_n, "rb");
  if (in == NULL) {
    fprintf(stderr, "data unreadable: %s at %d\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }
  acc old_user;
  while (fread(&old_user, sizeof(acc), 1, in) == 1) {
    if (strcmp(old_user.user_n, user_n) == 0) {
      if (strcmp(old_user.pw, pw) == 0) {
        strcpy(logged_in_as.user_n, old_user.user_n);
        strcpy(logged_in_as.pw, old_user.pw);
        logged_in_as.balance = old_user.balance;
        printf("Welcome %s\n", logged_in_as.user_n);
        fclose(in);
        return;
      } else {
        puts("Wrong password, please login again.");
        fclose(in);
        return;
      }
    } else {
      if (feof(in)) {
        break;
      } else if (ferror(in)) {
        printf("Error reading %s\n", in_n);
        exit(EXIT_FAILURE);
      }
    }
  }
  puts("User could not be found\n");
  fclose(in);
}
