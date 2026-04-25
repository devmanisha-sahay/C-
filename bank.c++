#include <iostream>
#include <string>
using namespace std;

struct Account {
    int accNo;
    string name;
    float balance;
};

Account accounts[100];   // store up to 100 accounts
int countAcc = 0;

void createAccount() {
    if (countAcc < 100) {
        cout << "Enter Account Number: ";
        cin >> accounts[countAcc].accNo;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, accounts[countAcc].name);
        cout << "Enter Initial Balance: ";
        cin >> accounts[countAcc].balance;
        countAcc++;
        cout << "Account created successfully!\n";
    } else {
        cout << "Bank storage full!\n";
    }
}

void depositMoney() {
    int accNo;
    float amount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    for (int i = 0; i < countAcc; i++) {
        if (accounts[i].accNo == accNo) {
            accounts[i].balance += amount;
            cout << "Deposit successful! New Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found!\n";
}

void withdrawMoney() {
    int accNo;
    float amount;
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    for (int i = 0; i < countAcc; i++) {
        if (accounts[i].accNo == accNo) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                cout << "Withdrawal successful! New Balance: " << accounts[i].balance << endl;
            } else {
                cout << "Insufficient balance!\n";
            }
            return;
        }
    }
    cout << "Account not found!\n";
}

void checkBalance() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < countAcc; i++) {
        if (accounts[i].accNo == accNo) {
            cout << "Account Holder: " << accounts[i].name << endl;
            cout << "Balance: " << accounts[i].balance << endl;
            return;
        }
    }
    cout << "Account not found!\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n===== Bank Management System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: checkBalance(); break;
            case 5: cout << "Exiting... Goodbye!\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}