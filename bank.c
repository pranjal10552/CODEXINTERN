#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Account structure
typedef struct Account
{
    char name[50];
    int accNo;
    float balance;
}Account;

Account accounts[MAX];  // Array to store multiple accounts

// Variables for file handling
int count = 0;
const char *filename = "accounts.dat";

// Function prototypes
void load();
void save();
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void listAccounts();

int main() 
{
    int choice;
    load();  // Load existing accounts

    while (1) 
    {
        printf("\n--- Bank Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. List Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice(1-6): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: listAccounts(); break;
            case 6: save(); printf("Data saved.\n"); 
                    exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Load accounts from file
void load() 
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL) return; // on the first run, there will be no file
    fread(&count, sizeof(int), 1, f);
    fread(accounts, sizeof(Account), count, f);
    fclose(f);
}

// Save accounts to file
void save() 
{
    FILE *f = fopen(filename, "wb");
    if (f == NULL) 
    {
        printf("Error saving file.\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, f);
    fwrite(accounts, sizeof(Account), count, f);
    fclose(f);
}

// Create new account
void createAccount() 
{
    if (count >= MAX) 
    {
        printf("Bank database full.\n");
        return;
    }

    Account a;
    printf("Enter account number: ");
    scanf("%d", &a.accNo);

    // Check duplicate account number
    for (int i = 0; i < count; i++)
     {
        if (accounts[i].accNo == a.accNo) 
        {
            printf("Error: Account number already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    getchar(); 
    fgets(a.name, sizeof(a.name), stdin); // input name
    a.name[strcspn(a.name, "\n")] = '\0';

    printf("Enter initial deposit: ");  // input deposit amount
    scanf("%f", &a.balance);

    if (a.balance < 0) // balance check
    {
        printf("Error: Initial balance cannot be negative.\n");
        return;
    }

    accounts[count++] = a;
    save();
    printf("Account created successfully.\n");
}

// Deposit money
void deposit() 
{
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) 
    {
        if (accounts[i].accNo == accNo) 
        {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            if (amount <= 0) 
            {
                printf("Error: Invalid amount.\n");
                return;
            }
            accounts[i].balance += amount;
            save();
            printf("Deposit successful. \nNew balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Withdraw money
void withdraw() 
{
    int accNo;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) 
    {
        if (accounts[i].accNo == accNo) 
        {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);
            if (amount <= 0) 
            {
                printf("Error: Invalid amount.\n");
                return;
            }
            if (amount > accounts[i].balance) 
            {
                printf("Error: Insufficient balance.\n");
                return;
            }
            accounts[i].balance -= amount;
            save();
            printf("Withdrawal successful. \nNew balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Check account balance
void checkBalance() 
{
    int accNo;
    printf("Enter account number: ");
    scanf("%d", &accNo);

    for (int i = 0; i < count; i++) 
    {
        if (accounts[i].accNo == accNo) 
        {
            printf("Account: %d | Name: %s | Balance: %.2f\n",accounts[i].accNo, accounts[i].name, accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// List all accounts
void listAccounts() 
{
    if (count == 0) 
    {
        printf("No accounts available.\n");
        return;
    }
    printf("\n--- All Accounts ---\n");
    for (int i = 0; i < count; i++) 
    {
        printf("AccNo: %d | Name: %s | Balance: %.2f\n",accounts[i].accNo, accounts[i].name, accounts[i].balance);
    }
}
