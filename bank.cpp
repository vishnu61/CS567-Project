#include "bank.h"
#include <iostream>
#include <string>

void initializeAccounts(Account accounts[]) {
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        accounts[i].account_number = -1;
        accounts[i].holder_name[0] = '\0';
        accounts[i].balance = 0.0;
    }
}

int createAccount(Account accounts[], int account_number, std::string holder_name) {
    int index = -1;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (accounts[i].account_number == -1) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        accounts[index].account_number = account_number;
        strcpy(accounts[index].holder_name, holder_name.c_str());
        accounts[index].balance = 0.0;
    }

    return index;
}

float checkBalance(Account accounts[], int account_number) {
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (accounts[i].account_number == account_number) {
            return accounts[i].balance;
        }
    }
    return -1;
}

void deposit(Account accounts[], int account_number, float amount) {
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            std::cout << "Deposited " << amount << " into account " << account_number << std::endl;
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void withdraw(Account accounts[], int account_number, float amount) {
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                std::cout << "Withdrawn " << amount << " from account " << account_number << std::endl;
            } else {
                std::cout << "Insufficient balance for withdrawal from account " << account_number << std::endl;
            }
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void transfer(Account accounts[], int from_account, int to_account, float amount) {
    withdraw(accounts, from_account, amount);
    deposit(accounts, to_account, amount);
    std::cout << "Transferred " << amount << " from account " << from_account << " to account " << to_account << std::endl;
}

void displayAllAccounts(Account accounts[]) {
    std::cout << "All Accounts:" << std::endl;
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (accounts[i].account_number != -1) {
            std::cout << "Account Number: " << accounts[i].account_number << ", Holder Name: " << accounts[i].holder_name << ", Balance: " << accounts[i].balance << std::endl;
        }
    }
}

void closeAccount(Account accounts[], int account_number) {
    for (int i = 0; i < MAX_ACCOUNTS; ++i) {
        if (accounts[i].account_number == account_number) {
            accounts[i].account_number = -1;
            accounts[i].holder_name[0] = '\0';
            accounts[i].balance = 0.0;
            std::cout << "Account " << account_number << " closed successfully" << std::endl;
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void printMenu() {
    std::cout << "\nBanking Application Menu:" << std::endl;
    std::cout << "1. Create Account" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Transfer" << std::endl;
    std::cout << "5. Check Balance" << std::endl;
    std::cout << "6. Display All Accounts" << std::endl;
    std::cout << "7. Close Account" << std::endl;
    std::cout << "8. Exit" << std::endl;
}

// int main() {
//     Account accounts[MAX_ACCOUNTS];
//     initializeAccounts(accounts);

//     int choice;
//     int account_number, to_account_number;
//     std::string holder_name;
//     float amount;

//     do {
//         printMenu();
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;

//         switch (choice) {
//             case 1:
//                 std::cout << "Enter account number: ";
//                 std::cin >> account_number;
//                 std::cout << "Enter holder name: ";
//                 std::cin >> holder_name;
//                 createAccount(accounts, account_number, holder_name);
//                 break;
//             case 2:
//                 std::cout << "Enter account number: ";
//                 std::cin >> account_number;
//                 std::cout << "Enter amount to deposit: ";
//                 std::cin >> amount;
//                 deposit(accounts, account_number, amount);
//                 break;
//             case 3:
//                 std::cout << "Enter account number: ";
//                 std::cin >> account_number;
//                 std::cout << "Enter amount to withdraw: ";
//                 std::cin >> amount;
//                 withdraw(accounts, account_number, amount);
//                 break;
//             case 4:
//                 std::cout << "Enter account number to transfer from: ";
//                 std::cin >> account_number;
//                 std::cout << "Enter account number to transfer to: ";
//                 std::cin >> to_account_number;
//                 std::cout << "Enter amount to transfer: ";
//                 std::cin >> amount;
//                 transfer(accounts, account_number, to_account_number, amount);
//                 break;
//             case 5:
//                 std::cout << "Enter account number: ";
//                 std::cin >> account_number;
//                 std::cout << "Balance: " << checkBalance(accounts, account_number) << std::endl;
//                 break;
//             case 6:
//                 displayAllAccounts(accounts);
//                 break;
//             case 7:
//                 std::cout << "Enter account number to close: ";
//                 std::cin >> account_number;
//                 closeAccount(accounts, account_number);
//                 break;
//             case 8:
//                 std::cout << "Exiting..." << std::endl;
//                 break;
//             default:
//                 std::cout << "Invalid choice" << std::endl;
//         }
//     } while (choice != 8);

//     return 0;
// }
