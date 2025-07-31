#ifndef ATM_H
#define ATM_H
#define MAX_ACCOUNT 100
#define LIMIT 50000.00
typedef struct
{
    char name[50];
    char account_no[30];
    int pin;
    double balance;
} User;

void show_menu(User *user, int i, int total_user);
void deposit_money(User *user, int i);
void withdraw_money(User *user, int i);
void pin_change(User *user, int i);
int load_data(User *user);
void update_user_balance(User *user, int total_user);
void processing();
void print_receipt(char *name, char *account_no, double balance, double amount, char *transaction_type);

#endif
