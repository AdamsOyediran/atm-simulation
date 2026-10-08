#include<stdio.h>
void print_menu(void);

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

    printf("ENTER YOUR PIN(4-DIGIT):\n");
    scanf("%d", &ent_pin);
    
    if (pin != ent_pin)
    {
        while (ent_pin != pin)
        {
            printf("INCORRECT PIN.\n");
            printf("ENTER CORRECT PIN(4-DIGIT):\n");
            scanf("%d", &ent_pin);

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

    printf("ENTER ACTION(1-2)\n");
    scanf("%d", &screen);

    switch (screen)
    {
        
    case 1:
        print_menu();
        printf("ENTER ACTION(1-5)\n");
        scanf("%d", &action);
        
        switch (action)
        {
        case 1:
                printf("==ACCOUNT BALANCE==\n");
                printf("$%d\n", acct_bal);
            break;

        case 2:
                printf("==DEPOSIT==\n");
                printf("ENTER DEPOSIT AMOUNT\n");
                scanf("%d", &depo);
                acct_bal += depo;
                
            
                printf("ACCOUNT BALANCE: $%d\n", acct_bal);
            break;
        
        
        case 3:
                printf("==WITHDRAW==\n");
                printf("ENTER WITHDRAWAL AMOUNT\n");
                scanf("%d", &wdraw);

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
                printf("ENTER NEW PIN(4-DIGIT):\n");
                scanf("%d", &new_pin);
            
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
            printf("ACCOUNT BALANCE: $%d\n", acct_bal);

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