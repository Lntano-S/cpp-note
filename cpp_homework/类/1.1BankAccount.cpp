#include <iostream>

class BankAccount {
private:
    int balance;

public:
    BankAccount() {
        balance = 0;
    }  

    BankAccount(int m = 0) : balance(m) {}

    int getbalance() {
        return balance;
    }

    void withdraw(int m) {
        if (m <= balance) {
            balance -= m;
        } else {
            std::cout << "Insufficient balance.";
        }
    }

    void deposit(int m) {
        balance += m;
    }
};

int main(void) {
    int balance, n, amount;
    char operation;
    std::cin >> balance;
    std::cin >> n;

    BankAccount account_1 = BankAccount(balance);

    for (int i = 0; i < n; ++i) {
        std::cin >> operation >> amount;

        if (operation == 'w') {
            account_1.withdraw(amount);
            std::cout << "balance: " << account_1.getbalance() << "\n"; 
        } else if (operation == 'd') {
            account_1.deposit(amount);
            std::cout << "balance: " << account_1.getbalance() << "\n"; 
        }
    }


    return 0;
}