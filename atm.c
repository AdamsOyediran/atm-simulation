#include<stdio.h>
void print_menu(void);
int read_int(const char *prompt);

int main(void)
{
    int pin = 1234;
    int ent_pin;
    int action;
    int screen;
    int acct_bal = 1000000;
    int depo;
    int wdraw;
    int new_pin;
    char name[50] = "ADAMS OYEDIRAN";
    long int acct_number = 9078803030;
    
    
    printf("===ATM SIMULATION===\n");
    printf("=====WELCOME TO OPAY====\n");

    ent_pin = read_int("ENTER YOUR PIN(4-DIGIT): ");
    
    if (pin != ent_pin)
    {
        while (ent_pin != pin)
        {
            printf("INCORRECT PIN.\n");
            ent_pin = read_int("ENTER YOUR PIN(4-DIGIT): ");

            if (pin == ent_pin)
            {
                printf("==LOGIN SUCCESSFUL==\n");
            }
        }
        
    }
    else if ( pin == ent_pin)
    {
        printf("==SUCCESSFUL LOG IN==\n");
    }

    printf("1 ===MAIN MENU===\n");
    printf("2 ===ACCOUNT DATA===\n");

    screen = read_int("ENTER ACTION(1-2): ");

    switch (screen)
    {
        
    case 1:
        print_menu();
        action = read_int("ENTER ACTION(1-5): ");
        
        switch (action)
        {
        case 1:
                printf("==ACCOUNT BALANCE==\n");
                printf("#%d\n", acct_bal);
            break;

        case 2:
                printf("==DEPOSIT==\n");
                depo = read_int("ENTER DEPOSIT AMOUNT: ");
                acct_bal += depo;
                
            
                printf("ACCOUNT BALANCE: #%d\n", acct_bal);
            break;
        
        
        case 3:
                printf("==WITHDRAW==\n");
                wdraw = read_int("ENTER WITHDRAWAL AMOUNT:");
                if (wdraw > acct_bal)
                {
                    printf("INSUFFICIENT FUNDS\n");
                }
                else
                {
                    acct_bal -= wdraw;
                    printf("ACCOUNT BALANCE: $%d\n", acct_bal);
                }
            break;
        
        case 4:
        
                printf("==RESET PIN==\n");
                new_pin = read_int("ENTER NEW PIN(4-DIGIT): ");
            
                pin = new_pin;
                printf("NEWPIN: %d\n", pin);
        
            break;

        case 5:
                printf("==EXIT==\n");
                printf("THANK YOU FOR USING OPAY\n");
            break;

        default:
                printf("INVALID ACTION\n");
        }
        break;

    case 2:
            printf("===ACCOUNT DATA===\n");
            printf("ACCOUNT NAME: %s\n", name);
            printf("PIN: %d\n", pin);
            printf("ACCOUNT NUMBER: %ld\n", acct_number);
            printf("ACCOUNT BALANCE: #%d\n", acct_bal);

        break;

    default:
        printf("INVALID ACTION\n");
    }

    return 0;
}

void print_menu(void)
{
    printf("\n=== MAIN MENU ===\n");
    printf("1 Account balance\n");
    printf("2 Deposit\n");
    printf("3 Withdraw\n");
    printf("4 Change PIN\n");
    printf("5 Exit\n");
}

int read_int(const char *prompt)
{
    int value;
    int result;

    while (1)
    {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == 1)
        {
            return value;
        }
        else
        {
            printf("That is not a number. Try again.\n");
        }

        while (getchar() != '\n')
        {
            ;
        }
    }
}