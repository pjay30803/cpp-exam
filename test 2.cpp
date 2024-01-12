#include <iostream>
#include <string>

class BankAccount {
private:
    int accountNumber;
    double balance;
    std::string ownerName;

public:
    BankAccount(int accNum, double initialBalance, std::string owner)
        : accountNumber(accNum), balance(initialBalance), ownerName(owner) {}

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!\n";
        }
    }

    void displayBalance() {
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Owner Name: " << ownerName << "\n";
        std::cout << "Balance: /-" << balance << "\n";
    }
};

int main() {
    BankAccount myAccount(12345, 1000.0, "Jay");

    myAccount.displayBalance();

    myAccount.credit(500.0);
    std::cout << "Credited 500/- to the account.\n";

    myAccount.displayBalance();

    myAccount.debit(200.0);
    std::cout << "Debited 200/- from the account.\n";

    myAccount.displayBalance();

    return 0;
}
