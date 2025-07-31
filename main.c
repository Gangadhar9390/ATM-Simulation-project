#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atm.h"
#include <unistd.h>
int main()
{

    int usr_pin, count = 0, remaining_attempts = 3, digit_count = 0,
                 choice, balance = 0, check_pin, flag_acc = 0, flag_pin = 0, flag = 0, i, j;
    User user[MAX_ACCOUNT];
    char acc_no[20];
    int total_user = load_data(user);
    printf("=========================================\n");
    printf("     🏦 Welcome to SBI ATM\n");
    printf("=========================================\n");
    while (1)
    {
        if (!flag_acc)
        {
            printf("\n👉 Enter your Account Number: ");
            scanf("%s", acc_no);
            processing();
            j = 1;
            int is_valid = 1;
            if (strlen(acc_no) != 11)
                is_valid = 0;
            else
            {
                for (j = 0; j < 10; j++)
                {
                    if (acc_no[j] < '0' || acc_no[j] > '9')
                    {
                        is_valid = 0;
                        break;
                    }
                }
            }

            for (i = 0; i < total_user; i++)
            {
                if (strcmp(user[i].account_no, acc_no) == 0)
                {
                    printf("✅ Account Found.\n");
                    flag_acc = 1;
                    break;
                }
            }
            if (!flag_acc)
            {
                if (!is_valid)
                    printf("\n⚠️ Account number must be exactly 11 digits\n");
                printf("\n❌ Invalid account number !Please try again.\n");
                continue;
            }
        }
        if (!flag_pin)
        {
            printf("\n🔐 Enter your 4-digit PIN: ");
            if (scanf("%d", &usr_pin) != 1)
            {
                while (getchar() != '\n')
                    ;
                printf("\n❌ Invalid input! Please enter digits 0 to 9 only.\n\n");
                continue;
            }
            count++;
            remaining_attempts--;
            check_pin = usr_pin;
            while (check_pin)
            {
                digit_count++;
                check_pin = check_pin / 10;
            }
        }
        if (usr_pin == user[i].pin || flag_pin)
        {
            flag_pin = 0;
            printf("\n✅ Verified PIN\n");
            show_menu(user, i, total_user);
            printf("Do you want to continue the transaction (Y/y): ");
            char ch;
            scanf(" %c", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                processing();
                continue;
            }
            else
            {
                printf("\nLogging out");
                for (int j = 0; j < 3; j++)
                {
                    printf(".");
                    fflush(stdout);
                    sleep(1);
                }
                printf("\n");
                break;
            }
        }
        else if (remaining_attempts != 0)
        {
            if (digit_count != 4)
            {
                printf("\n❌ Please enter a valid 4-digit PIN\n\n");
            }
            printf("\n⚠️ Invalid PIN\nYou have %d attempt(s) remaining.\n", remaining_attempts);
            continue;
        }
        if (count == 3)
        {
            printf("\n🚫 Your card has been blocked due to 3 incorrect attempts. Contact your bank.\n");
            return 1;
        }
    }
    return 0;
}
