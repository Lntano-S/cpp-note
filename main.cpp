#include <iostream>
#include <string>

class BankAccount {
// 私有变量
private:    
    int account_id;
    double balance;

// 公有变量
public:
    std::string owner_name;
    static double total_bank_money;
    static int active_accounts;

    // 构造函数
    BankAccount(
        const std::string &_owner_name,
        int _account_id,
        double _balance
    ) : owner_name(_owner_name), 
        account_id(_account_id), 
        balance(_balance) {
        active_accounts++;
        total_bank_money += balance;
    }

    // 析构函数
    ~BankAccount() {
        std::cout << "账户 [" << account_id << "] 已销毁" << std::endl;
        active_accounts--;
        total_bank_money -= balance;
    }

    // 成员函数
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < balance) {
            balance -= amount;
        } else {
            std::cout << "余额不足，取款失败" << std::endl;
        }
    }

    const double get_balance() const {
        return balance;
    }

    const void show_info() const {
        std::cout << "-----此账户详情-----" << std::endl;
        std::cout << "姓名：" << owner_name << std::endl;
        std::cout << "账户ID: " << account_id << std::endl;
        std::cout << "账户余额：" << balance << std::endl;
    }

    static void get_bank_summary() {
        std::cout << "总人数：" << active_accounts << std::endl;
        std::cout << "总资金池：" << total_bank_money << "元" << std::endl;
    }
};

