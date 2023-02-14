#include <stdio.h>

struct Account
{
    int account_number;
    char name[100];
    double balance;
};

struct Account accounts[100]; // assuming max 100 accounts

int num_accounts = 0;

void add_account()
{
    struct Account account;
    printf("Enter account number: ");
    scanf("%d", &account.account_number);
    printf("Enter name: ");
    scanf("%s", account.name);
    printf("Enter balance: ");
    scanf("%lf", &account.balance);
    accounts[num_accounts] = account;
    num_accounts++;
}

void delete_account()
{
    int account_number, index = -1;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int i;
    for (i = 0; i < num_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Account not found.\n");
    }
    else
    {
        for (i = index; i < num_accounts - 1; i++)
        {
            accounts[i] = accounts[i + 1];
        }
        num_accounts--;
        printf("Account deleted successfully.\n");
    }
}

void search_account()
{
    int account_number, index = -1;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int i;
    for (i = 0; i < num_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Account not found.\n");
    }
    else
    {
        printf("Account number: %d\n", accounts[index].account_number);
        printf("Name: %s\n", accounts[index].name);
        printf("Balance: %lf\n", accounts[index].balance);
    }
}

void deposit()
{
    int account_number, index = -1;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int i;
    for (i = 0; i < num_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Account not found.\n");
    }
    else
    {
        printf("Enter amount to deposit: ");
        scanf("%lf", &amount);
        accounts[index].balance += amount;
        printf("Amount deposited successfully.\n");
    }
}

void withdraw_money()
{
    int account_number, index = -1;
    double amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    int i;
    for (i = 0; i < num_accounts; i++)
    {
        if (accounts[i].account_number == account_number)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Account not found.\n");
    }
    else
    {
        printf("Enter amount to withdraw: ");
        scanf("%lf", &amount);
        if (amount > accounts[index].balance)
        {
            printf("Insufficient balance.\n");
        }
        else
        {
            accounts[index].balance -= amount;
            printf("Amount withdrawn successfully.\n");
        }
    }
}

void display_menu()
{
    printf("\nBank Management System\n");
    printf("----------------------\n");
    printf("1. Add account\n");
    printf("2. Delete account\n");
    printf("3. Search account\n");
    printf("4. Deposite Money\n");
    printf("5. Withdraw Money\n");
    printf("6.Exit");
}

int main()
{
    printf("All provided operations are: ");
    display_menu();
    int n;
    while (n!=6)
    {
    	    printf("\nEnter your choice: ");
    scanf("\n%d", &n);
        switch (n)
        {
        case 1:
            add_account();
            break;
        case 2:
            delete_account();
            break;
        case 3:
            search_account();
            break;
        case 4:
            deposit();
            break;
        case 5:
            withdraw_money();
            break;
        case 6:
            printf("Exiting...\t Thanks for choosing us.");
            break;

        default:
            printf("\nPlease enter a valid choice.\n");
            break;
        }
    }
}
