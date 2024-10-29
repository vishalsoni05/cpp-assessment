
#include <iostream>
using namespace std;

class ATM {
private:
    int pin = 12345;
    double balance = 20000;
    double initialBalance = 60000;
    string accountHolderName = "Rakesh Kharva";
    string accountHolderAddress = "Mumbai";
    string branchLocation = "Andheri";
    string accountNumber = "5678";

public:
    ATM() {
        cout << "Welcome to ATM Banking Application" << endl;
        cout << "Press 1 and Enter to access your account via PIN number" << endl;
        cout << "Press 0 and Enter to get help: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            runATM();
        } else if (choice == 0) {
            cout << "\nYou must have the correct pin number to access this account see your\nbank representative for assistant during Bank opening our\nthanks for,your choice today!! then press any key to continue. = ";
            cin.get();
            cin.get();
        } else {
            cout << "Invalid choice. Exiting..." << endl;
        }
    }

    void displayMenu() {
        cout << "\nATM Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
    }

    void runATM() {
        int choice, attempt = 0;
        int enteredPin;

        while (attempt < 3) {
            cout << "\nEnter your ATM PIN: ";
            cin >> enteredPin;
            if (enteredPin == pin) {
                attempt = 3;
                while (true) {
                    displayMenu();
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            checkBalance();
                            break;
                        case 2:
                            deposit();
                            break;
                        case 3:
                            withdraw();
                            break;
                        case 4:
                            cout << "Thank you for using ATM Banking Application." << endl;
                            return;
                        default:
                            cout << "Invalid choice. Please choose again." << endl;
                    }
                }
            } else {
                attempt++;
                cout << "You had made " << attempt << " attempt which failed!! No more attempt allowed!! Sorry!!" << endl;
                cin.get();
                cin.get();
                return;
            }
        }
    }

    void checkBalance() {
        cout << "\nAccount Holder Name: " << accountHolderName << endl;
        cout << "Account Holder Address: " << accountHolderAddress << endl;
        cout << "Branch Location: " << branchLocation << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Present Balance Available: Rs. " << balance << endl;
        cout << "Press any key to continue..." << endl;
        cin.get();
        cin.get();
    }

    void deposit() {
        cout << "\nAccount Holder Name: " << accountHolderName << endl;
        cout << "Account Holder Address: " << accountHolderAddress << endl;
        cout << "Branch Location: " << branchLocation << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Present Balance Available: Rs. " << balance << endl;

        double amount;
        cout << "\nEnter amount to deposit: Rs. ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Your new available amount is Rs. " << balance << endl;
            cout << "Thank you!" << endl;
            cout << "Press any key to return to main menu..." << endl;
            cin.get();
            cin.get();
        } else {
            cout << "Invalid deposit amount." << endl;
            cout << "Press any key to continue..." << endl;
            cin.get();
            cin.get();
        }
    }

    void withdraw() {
        cout << "\nAccount Holder Name: " << accountHolderName << endl;
        cout << "Account Holder Address: " << accountHolderAddress << endl;
        cout << "Branch Location: " << branchLocation << endl;
        cout << "Account Number: " << accountNumber << endl;

        double amount;
        cout << "\nEnter amount to withdraw: Rs. ";
        cin >> amount;

        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: Rs. " << balance << endl;
            cout << "Thank you!" << endl;
            cout << "Press any key to return to main menu..." << endl;
            cin.get();
            cin.get();
        } else {
            cout << "Insufficient available balance in your account. Sorry!!" << endl;
            cout << "Press any key to continue..." << endl;
            cin.get();
            cin.get();
        }
    }
};

int main() {
    ATM atm;

    return 0;
}
