#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Account {
private:
    double balance;

public:
    int accountNumber;
    string ownerName;

    Account(int accNum, string name, double blnce) {
        accountNumber = accNum;
        ownerName = name;
        balance = blnce;
    }

    virtual ~Account(){};   // Destructor

    // Member functions
    void getAccountDetails(){
        cout << endl;
        cout << "Your Account Name: " << ownerName << endl;
        cout << "Your Account Number:" << accountNumber << endl;
        cout << "Your Balance is: $" << balance << endl <<endl;

        return;
    }

    void getBalance() {
        cout << "Your Balance is $" << balance << endl;

        return;
    }

    void depositMoney(double amount) {
        balance += amount;
        cout << endl;
        cout << "Deposit Successful" << endl;
        cout << "Your Balance is $" << balance << endl;

        return;
    }

    void withdrawMoney(double amount) {
        balance -= amount;

        cout << endl;
        cout << "Withdraw Successful" << endl;
        cout << "Your Balance is $" << balance << endl;

        return;
    }

    void transferMoney(Account& transferAccount, double amount) {
        if(balance - amount >= 0) {
            balance -= amount;
            transferAccount.balance += amount;

            cout << endl;
            cout << "Transfer Successful" << endl;
            cout << "Your Balance is $" << balance << endl;
        } else {
            cout << endl;
            cout << "Unable to make transfer. Insufficient balance" << endl;
        }  

        return;
    }
};

class SavingsAccount: public Account{
    private:
        double interestRate;
};

class CurrentAccount: public Account{
    private:
    double overdraftLimit;
};

// Function Prototypes
void createAccount(vector<Account>& accounts);
void viewAccountDetails();
void depositMoney();
void withdrawMoney();
void transferMoney();

// Function Logic
void createAccount(vector<Account>& accounts) {
    string name;
    int accountNumber;
    double accountBalance = 0.0;

    cout << "Enter your name: ";
    cin >> name;
    cout << endl;

    if (accounts.empty()) {
        accountNumber = 1000;
    } else {
        accountNumber = accounts.back().accountNumber + 1;
    }

    accounts.push_back(Account(accountNumber, name, accountBalance));

    cout << "Congratulations!! Your account has been successfully created" << endl;
    accounts.back().getAccountDetails();
}

void viewAccountDetails() {
    // Function logic to view account details
}

void depositMoney() {
    // Function logic to deposit money
}

void withdrawMoney() {
    // Function logic to withdraw money
}

void transferMoney() {
    // Function logic to transfer money
}

int main() {
    vector<Account> accounts;
    int choice;

    do {
        cout << endl << "--------------------------------------------\n";
        cout << "Welcome to Bank Account Management System\n";
        cout << "1. Create Account\n";
        cout << "2. View Account Details\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Transfer Money\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                viewAccountDetails();
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawMoney();
                break;
            case 5:
                transferMoney();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
