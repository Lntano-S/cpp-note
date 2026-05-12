#include <bits/stdc++.h>

using namespace std;

class BusCard {
private:
    int id;
    string name;
    double balance;
    static double gen_deposit;
    static double gen_balance;

public:
    BusCard(int _id = 0, 
            string _name = " ", 
            double _balance = 0)
        :   id(_id), name(_name), balance(_balance) {}

    BusCard(const BusCard& cd) 
        :   id(cd.id), name(cd.name), balance(cd.balance) {}

    ~BusCard() {}

    void deposit(double amount) {
        balance += amount;
        gen_deposit += amount;
        gen_balance += amount;
    }

    void consume(double amount) {
        if (amount <= balance) {
            balance -= amount;
            gen_balance -= amount;
            cout << "消费成功! " << name << " 余额：" << balance << "\n";
            cout << "所有卡总余额：" << Get_gen_balance() << "\n";
        } else {
            cout << "余额不足！当前余额：" << balance << "\n";
        }
    }

    double Getbalance() const {
        return balance;
    }

    int Getid() const {
        return id;
    }

    string Getname() const {
        return name;
    }

    static double Get_gen_deposit() {
        return gen_deposit;
    }

    static double Get_gen_balance() {
        return gen_balance;
    }
};

double BusCard::gen_deposit = 0.0;
double BusCard::gen_balance = 0.0;


int main(void) {
    BusCard cd1(1001, "Tom");
    BusCard cd2(1002, "Jack");

    cout << "创建 Tom 和 Jack 的两张卡后，所有卡总余额：" << BusCard::Get_gen_balance() << "\n\n";

    cout << "--- Tom 充值 100 元 ---\n";
    cd1.deposit(100.0);
    cout << "Tom 余额：" << cd1.Getbalance() << "\n";
    cout << "所有卡总余额：" << BusCard::Get_gen_balance() << "\n\n";

    cout << "--- Jack 充值 50 元 ---\n";
    cd2.deposit(50.0);
    cout << "Jack 余额：" << cd2.Getbalance() << "\n";
    cout << "所有卡总余额：" << BusCard::Get_gen_balance() << "\n\n";

    cout << "--- Tom 消费 2.5 元 ---\n";
    cd1.consume(2.5);

    cout << "\n--- Tom 尝试消费 200 元 ---\n";
    cd1.consume(200.0);

    cout << "\n--- Jack 消费 5 元 ---\n";
    cd2.consume(5.0);

    cout << "\n累计充值总额：" << BusCard::Get_gen_deposit() << "\n";

    return 0;
}