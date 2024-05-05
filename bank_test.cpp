#include <deepstate/DeepState.hpp> 
#include "bank.cpp" 

#define NUM_ACCOUNTS 5 // Define the number of accounts to be used in tests

// Test for creating accounts
TEST(Bank, CreateAccounts) {
    Account accounts[MAX_ACCOUNTS]; // Create an array of accounts
    initializeAccounts(accounts); // Initialize the accounts array

    // Loop to create a specified number of accounts
    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        char holder_name[NAME_LENGTH];
        // Generate a random holder name using DeepState
        sprintf(holder_name, "Account%d", DeepState_IntInRange(1000, 9999));
        // Generate a random account number using DeepState
        int account_number = DeepState_IntInRange(10000, 99999);
        // Create the account and assert that it was created successfully
        ASSERT_EQ(createAccount(accounts, account_number, holder_name), i);
    }
}

// Test for depositing and withdrawing funds
TEST(Bank, DepositAndWithdraw) {
    Account accounts[MAX_ACCOUNTS]; // Create an array of accounts
    initializeAccounts(accounts); // Initialize the accounts array

    // Generate a random account number using DeepState
    int account_number = DeepState_IntInRange(1000, 9999);
    // Create an account with a random account number and a fixed name "Alice"
    createAccount(accounts, account_number, "Alice");

    // Generate a random deposit amount using DeepState
    float deposit_amount = DeepState_IntInRange(1,1000);
    // Deposit the generated amount into the account
    deposit(accounts, account_number, deposit_amount);
    // Assert that the balance in the account matches the deposited amount
    ASSERT_EQ(checkBalance(accounts, account_number), deposit_amount);

    // Generate a random withdraw amount using DeepState
    float withdraw_amount = DeepState_IntInRange(1,1000);
    // Withdraw the generated amount from the account
    withdraw(accounts, account_number, withdraw_amount);
    // Assert that the balance in the account matches the deposited amount minus the withdrawn amount
    ASSERT_EQ(checkBalance(accounts, account_number), deposit_amount - withdraw_amount);
}

// Test for transferring funds between accounts
TEST(Bank, Transfer) {
    Account accounts[MAX_ACCOUNTS]; // Create an array of accounts
    initializeAccounts(accounts); // Initialize the accounts array

    // Generate a random account number using DeepState for the sender account
    int from_account = DeepState_IntInRange(1000, 9999);
    // Create an account with a random account number and a fixed name "Alice" for the sender account
    createAccount(accounts, from_account, "Alice");

    // Generate a random account number using DeepState for the recipient account
    int to_account = DeepState_IntInRange(1000, 9999);
    // Create an account with a random account number and a fixed name "Bob" for the recipient account
    createAccount(accounts, to_account, "Bob");

    // Generate a random deposit amount using DeepState for the sender account
    float deposit_amount = DeepState_IntInRange(1,1000);
    // Deposit the generated amount into the sender account
    deposit(accounts, from_account, deposit_amount);

    // Generate a random transfer amount using DeepState
    float transfer_amount = DeepState_IntInRange(1,1000);
    // Transfer the generated amount from the sender account to the recipient account
    transfer(accounts, from_account, to_account, transfer_amount);
    // Assert that the balance in the sender account is decreased by the transfer amount
    ASSERT_EQ(checkBalance(accounts, from_account), deposit_amount - transfer_amount);
    // Assert that the balance in the recipient account matches the transfer amount
    ASSERT_EQ(checkBalance(accounts, to_account), transfer_amount);
}

// Test for closing an account
TEST(Bank, CloseAccount) {
    Account accounts[MAX_ACCOUNTS]; // Create an array of accounts
    initializeAccounts(accounts); // Initialize the accounts array

    // Generate a random account number using DeepState
    int account_number = DeepState_IntInRange(1000, 9999);
    // Create an account with a random account number and a fixed name "Alice"
    createAccount(accounts, account_number, "Alice");

    // Close the account with the generated account number
    closeAccount(accounts, account_number);
    // Assert that the balance in the closed account is -1, indicating it's closed
    ASSERT_EQ(checkBalance(accounts, account_number), -1);
}

// Main function to initialize DeepState and run the tests
// int main(int argc, char **argv) {
//     DeepState_InitOptions(argc, argv); // Initialize DeepState options
//     DeepState_Run(); // Run the DeepState tests
//     return 0;
// }
