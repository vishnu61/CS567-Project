#ifndef BANK_H
#define BANK_H

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

#include <string>

struct Account {
    int account_number;
    char holder_name[NAME_LENGTH];
    float balance;
};

void initializeAccounts(Account accounts[]);
int createAccount(Account accounts[], int account_number, std::string holder_name);
float checkBalance(Account accounts[], int account_number);
void deposit(Account accounts[], int account_number, float amount);
void withdraw(Account accounts[], int account_number, float amount);
void transfer(Account accounts[], int from_account, int to_account, float amount);
void displayAllAccounts(Account accounts[]);
void closeAccount(Account accounts[], int account_number);

#endif
