#include <stdio.h>
#include <stdlib.h>
#include "atm.h"
#include <unistd.h>
#include <time.h>
void show_menu(User *user, int i, int total_user)
{
    int choice;
    printf("\n=========== 🏦 Main Menu ===========\n");
    printf("1️⃣  Check Balance\n");
    printf("2️⃣  Deposit Money\n");
    printf("3️⃣  Withdraw Money\n");
    printf("4️⃣  Change PIN\n");
    printf("5️⃣  Exit\n");
    printf("=====================================\n");

    while (1)
    {
        printf("Select one : ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("\n❌ Invalid input! Please enter digits 1 to 5 only.\n\n");
            continue;
        }
        break;
    }

    switch (choice)
    {
    case 1:
        processing();
        printf("\nYour balance is %g\n\n", user[i].balance);
        // printf("మీ బ్యాలెన్స్ ₹%d ఉంది\n", balance);
        break;
    case 2:
        processing();
        deposit_money(user, i);
        update_user_balance(user, total_user);
        break;
    case 3:
        processing();
        withdraw_money(user, i);
        update_user_balance(user, total_user);
        break;
    case 4:
        processing();
        pin_change(user, i);
        update_user_balance(user, total_user);
        break;
    case 5:
        printf("\n✅ Transaction complete. Please wait...\n");
        printf("\nLogging out");
        for (int j = 0; j < 3; j++)
        {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n\n🙏 Thank you for using SBI ATM.\n");
        printf("=========================================\n");
        exit(0);
    default:
        printf("\nInvalid option\n");
    }
}

void deposit_money(User *user, int i)
{
    while (1)
    {
        int balance, deposit, old_balance = user[i].balance, new_balance, flag = 0;
        char ch, ch1;
        printf("\nDeposit amount must be multiple of ₹100 or ₹200, or ₹500\n");
        printf("\nEnter the Deposit amount: ");
        if (scanf("%d", &deposit) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("\n❌ Invalid  !Please try again.\n");
            continue;
        }
        processing();
        if ((deposit >= 100) && ((deposit % 100) == 0) && (deposit <= LIMIT))
        {
            new_balance = old_balance + deposit;
            user[i].balance = new_balance;
            printf("\n✅ ₹%d deposited successfully into your account.\n", deposit);
            printf("Do you want receipt? (y/n): ");
            scanf(" %c", &ch1);
            if (ch1 == 'y' || ch1 == 'Y')
            {
                print_receipt(user[i].name, user[i].account_no, user[i].balance, deposit, "Deposit");
                flag = 1;
            }
            if (!flag)
            {
                printf("\nDo you want check your balance? (y/n) : ");
                scanf(" %c", &ch);
                if (ch == 'y' || ch == 'Y')
                    printf("\nYour balance is ₹%.2lf\n", user[i].balance);
            }
        }
        else if (deposit > LIMIT)
        {
            printf("\n⚠️ Deposit limit is ₹%.2lf only.\nPlease enter a lower amount.\n", LIMIT);

            continue;
        }

        else
        {
            printf("\n⚠️ Invalid amount!\nThis ATM accepts only ₹100, ₹200, and ₹500 notes.\n");
            printf("💡 Please enter a multiple of valid denominations (e.g., ₹1000, ₹1500).\n");
            continue;
        }
        break;
    }
}
void withdraw_money(User *user, int i)
{
    while (1)
    {
        int withdraw, balance, old_balance = user[i].balance, flag = 0;
        char ch, ch1;
        printf("\nWithdraw amount must be multiple of ₹100 or ₹200 or ₹500 \n");
        printf("\nEnter the withdraw amount: ");
        if (scanf("%d", &withdraw) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("\n❌ Invalid  !Please try again.\n");
            continue;
        }

        processing();
        if (withdraw > old_balance)
        {
            printf("\n❌ Transaction failed. You have insufficient funds.\n");
            return;
        }
        if ((withdraw >= 100) && ((withdraw % 100) == 0) && (withdraw <= LIMIT))
        {

            user[i].balance = old_balance - withdraw;

            printf("\n✅ ₹%d withdrawn successfully.\n", withdraw);
            printf("💵 Dispensing cash...\n");
            sleep(2);
            printf("📄 Please collect your cash.\n");
            printf("Do you want receipt? (y/n): ");
            scanf(" %c", &ch1);
            if (ch1 == 'y' || ch1 == 'Y')
            {
                print_receipt(user[i].name, user[i].account_no, user[i].balance, withdraw, "Withdraw");
                flag = 1;
            }
            if (!flag)
            {
                printf("\nDo you want check your balance? (y/n) : ");
                scanf(" %c", &ch);
                if (ch == 'y' || ch == 'Y')
                    printf("\nYour balance is ₹%.2lf\n", user[i].balance);
            }
        }

        else if (withdraw > 50000)
        {
            printf("\n⚠️ Withdraw limit is ₹%.2lf only.\nPlease enter a lower amount.\n", LIMIT);

            continue;
        }
        else
        {
            printf("\nInvalid amount. Please enter multiple of ₹100 or ₹200 or ₹500 only\n");
            continue;
        }
        break;
    }
}

void pin_change(User *user, int i)
{
    while (1)
    {
        int new_pin, check_pin, digit_count = 0;
        printf("\nEnter your new 4 digit pin:  ");
        scanf("%d", &new_pin);
        check_pin = new_pin;
        while (check_pin)
        {
            digit_count++;
            check_pin = check_pin / 10;
        }
        if (digit_count == 4)
        {
            user[i].pin = new_pin;
            processing();
            printf("\n✅ Successfully pin changed\n");
            return;
        }
        printf("\nPin should be only 4 digits\nPlease try again\n");
        continue;
    }
}
int load_data(User *user)
{
    FILE *fptr;
    fptr = fopen("users.csv", "r");
    if (fptr == NULL)
    {
        perror("Error at opening user file\n");
        return -1;
    }
    int i = 0;
    while (i < MAX_ACCOUNT)
    {
        if (fscanf(fptr, "%49[^,],%29[^,],%d,%lf\n", user[i].name, user[i].account_no, &user[i].pin, &user[i].balance) == 4)
            i++;
        else
            break;
    }
    fclose(fptr);
    return i;
}
void update_user_balance(User *user, int total_user)
{
    FILE *fptr;
    fptr = fopen("users.csv", "w");
    if (fptr == NULL)
    {
        perror("Error opening users.csv for writing\n");
        return;
    }

    for (int i = 0; i < total_user; i++)
    {
        fprintf(fptr, "%s,%s,%d,%g\n", user[i].name, user[i].account_no, user[i].pin, user[i].balance);
    }

    fclose(fptr);
}
void processing()
{
    printf("\n⏳ Processing your request");
    for (int j = 0; j < 3; j++)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}
void print_receipt(char *name, char *account_no,
                   double balance, double amount, char *transaction_type)
{
    time_t now;
    time(&now);

    printf("\n=====================================\n");
    printf("              🏦 ATM RECEIPT\n");
    printf("=====================================\n");
    printf("Date & Time      : %s", ctime(&now));
    printf("Customer Name    : %s\n", name);
    printf("Account Number   : %s\n", account_no);
    printf("Transaction Type : %s\n", transaction_type);
    printf("Amount           : ₹%.2f\n", amount);
    printf("Available Balance: ₹%.2f\n", balance);
    printf("=====================================\n");
    printf("          Thank You for Using\n");
    printf("            Our ATM Service\n");
    printf("=====================================\n");
}