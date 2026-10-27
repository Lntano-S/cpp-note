#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real; // 实部
    double imag; // 虚部

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend Complex add(const Complex& c1, const Complex& c2);

    void print() const {
        if (fabs(imag) < 1e-6) {
            cout << real << endl;
        } else if (imag > 0) {
            cout << real << "+" << imag << "i" << endl;
        } else {
            cout << real << "-" << fabs(imag) << "i" << endl;
        }
    }
};

Complex add(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    double r1, i1, r2, i2;
    
    if (cin >> r1 >> i1 >> r2 >> i2) {
        Complex c1(r1, i1);
        Complex c2(r2, i2);
        
        Complex sum = add(c1, c2);
        
        c1.print();
        c2.print();
        sum.print();
    }
    
    return 0;
}