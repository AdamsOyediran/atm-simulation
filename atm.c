#include<stdio.h>
void print_menu(void);
int read_int(const char *prompt);
void show_balance(int balance);
int do_deposit(int balance);
int do_withdraw(int balance);
int authenticate(int correct_pin);
int change_pin(int current_pin);

int main(void)
{
    int pin = 1234;
    int action;
    int acct_bal = 1000000;
    char name[50] = "ADAMS OYEDIRAN";
    long int acct_number = 9078803030;
    int running = 1;
    
    
    printf("=====ATM SIMULATION=====\n");
    printf("====WELCOME TO OPAY====\n");
    
    if (!authenticate(pin))
    {
        return 1;
    }

    while(running)
    {
        print_menu();
        action = read_int("ENTER ACTION(1-6): ");
        
        switch (action)
        {
        case 1:
                printf("==ACCOUNT BALANCE==\n");
                show_balance(acct_bal);
            break;

        case 2:
                printf("==DEPOSIT==\n");
                acct_bal = do_deposit(acct_bal);
                show_balance(acct_bal);
            break;
        
        
        case 3:
                printf("==WITHDRAW==\n");
                acct_bal = do_withdraw(acct_bal);
                show_balance(acct_bal);
            break;
        
        case 4:
        
                printf("==RESET PIN==\n");
                pin = change_pin(pin);
            break;

        case 5:
                printf("==EXIT==\n");
                printf("THANK YOU FOR USING OPAY\n");
                running = 0;
            break;

        case 6:
                printf("===ACCOUNT DATA===\n");
                printf("ACCOUNT NAME: %s\n", name);
                printf("ACCOUNT NUMBER: %ld\n", acct_number);
                show_balance(acct_bal);

            break;

        default:
                printf("INVALID ACTION\n");
        }
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
    printf("6 Account data\n");
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

void show_balance(int balance)
{
    printf("ACCOUNT BALANCE: $%d\n", balance);
}

int do_deposit(int balance)
{
    int amount = read_int("ENTER DEPOSIT AMOUNT: ");

    if (amount <= 0)
    {
        printf("INVALID AMOUNT\n");
        return balance;
    }

    balance += amount;
    return balance;
}

int do_withdraw(int balance)
{
    int amount = read_int("ENTER WITHDRAWAL AMOUNT: ");

    if (amount <= 0)
    {
        printf("INVALID AMOUNT\n");
        return balance;
    }

    if (amount > balance)
    {
        printf("INSUFFICIENT FUNDS\n");
        return balance;
    }

    balance -= amount;
    return balance;
}

int authenticate(int correct_pin)
{
    int attempts = 0;
    int entered_pin;

    while (attempts < 3)
    {
        entered_pin = read_int("ENTER YOUR PIN(4-DIGIT): ");

        if (entered_pin == correct_pin)
        {
            printf("==LOGIN SUCCESSFUL==\n");
            return 1; // Authentication successful
        }

        printf("INCORRECT PIN.\n");
        attempts++;
    }
    printf("TOO MANY FAILED ATTEMPTS. CARD BLOCKED.\n");
    return 0; // Authentication failed
}

int change_pin(int current_pin)
{
    int new_pin = read_int("ENTER NEW PIN(4-DIGIT): ");

    if (new_pin < 1000 || new_pin > 9999)
    {
        printf("INVALID PIN. MUST BE A 4-DIGIT NUMBER.\n");
        return current_pin; // Return the current pin if invalid
    }

    printf("PIN CHANGED SUCCESSFULLY.\n");
    return new_pin; // Return the new pin
}