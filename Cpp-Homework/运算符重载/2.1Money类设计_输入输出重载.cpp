#include <iostream>
using namespace std;

class Money {
private:
    int yuan; // 元
    int jiao; // 角
    int fen;  // 分

public:
    // 构造函数
    Money(int y = 0, int j = 0, int f = 0) : yuan(y), jiao(j), fen(f) {}

    // 1. 重载加法运算符 '+' 
    Money operator+(const Money& other) const {
        // 先计算分的总和，如果满10就需要向角进位
        int total_fen = this->fen + other.fen;
        int current_fen = total_fen % 10;     
        int carry_to_jiao = total_fen / 10;   

        // 计算角的总和（包含来自被加数、加数以及分位的进位）
        int total_jiao = this->jiao + other.jiao + carry_to_jiao;
        int current_jiao = total_jiao % 10;   
        int carry_to_yuan = total_jiao / 10;   

        // 计算元的总和
        int current_yuan = this->yuan + other.yuan + carry_to_yuan;

        // 返回相加后的新对象
        return Money(current_yuan, current_jiao, current_fen);
    }

    // 2. 重载输入流提取运算符 '>>'
    friend istream& operator>>(istream& in, Money& m) {
        in >> m.yuan >> m.jiao >> m.fen;
        return in; 
    }

    // 3. 重载输出流插入运算符 '<<'
    friend ostream& operator<<(ostream& out, const Money& m) {
        out << m.yuan << "Yuan" << m.jiao << "Jiao" << m.fen << "Fen";
        return out; 
    }
};

int main()
{
    Money tmp1,tmp2;
    cin >> tmp1;
    cin >> tmp2;
    cout << tmp1 << endl;
    cout << tmp2 << endl;
    cout << tmp1 + tmp2 << endl;
    return 0; 
}