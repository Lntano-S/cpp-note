#include <iostream>
#include <cmath> // 引入 cmath 库是为了使用 fabs 函数
using namespace std;

// 声明复数类 Complex
class Complex {
private:
    double real; // 实部
    double imag; // 虚部

public:
    // 构造函数，使用初始化列表（课件推荐做法）
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 声明友元函数 add
    // 友元函数不是类的成员函数，但它可以访问类的私有(private)成员
    // 按照课件的“传常引用”原则，入参使用 const Complex& 以提高效率并保证安全
    friend Complex add(const Complex& c1, const Complex& c2);

    // 成员函数：输出复数
    // 加上 const 表示这是一个常成员函数（课件第22-25页内容），不会修改对象的数据
    void print() const {
        // 这里参考了你课件第6页的输出逻辑
        if (fabs(imag) < 1e-6) {
            // 如果虚部为0（浮点数判0），只输出实部
            cout << real << endl;
        } else if (imag > 0) {
            // 虚部大于0，需要手动补充 "+" 号
            cout << real << "+" << imag << "i" << endl;
        } else {
            // 虚部小于0，直接输出或者用 "-" 配合绝对值
            cout << real << "-" << fabs(imag) << "i" << endl;
        }
    }
};

// 实现友元函数 add
// 注意：实现时不需要加 Complex:: 限定符，因为它不是成员函数
Complex add(const Complex& c1, const Complex& c2) {
    // 访问 c1 和 c2 的私有成员 real 和 imag 进行相加，并返回一个匿名的 Complex 新对象
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    double r1, i1, r2, i2;
    
    // 从键盘读入两个复数的实部和虚部
    if (cin >> r1 >> i1 >> r2 >> i2) {
        // 实例化两个复数对象
        Complex c1(r1, i1);
        Complex c2(r2, i2);
        
        // 调用友元函数求和
        Complex sum = add(c1, c2);
        
        // 依次输出结果
        c1.print();
        c2.print();
        sum.print();
    }
    
    return 0;
}