#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double image;

public:
    Complex(double _real = 0.0, double _image = 0.0)
        : real(_real), image(_image) {}

    Complex operator-() const {
        return Complex(-real, -image);
    }

    Complex& operator+=(const Complex& other) {
        this->real += other.real;
        this->image += other.image;
        return *this;
    }

    friend Complex operator+(const Complex& c1, const Complex& c2);

    void print() const {
        cout << this->real << " + " << this->image << "i" << "\n";
    }
};

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.image + c2.image);
}

int main(void) {
    Complex cm1(1.5, -2.3), cm2(3.3, 8.7), cm3, cm4;
    
    // 真正用上了运算符重载
    cm3 = -cm1;      // 隐式调用 operator-()
    cm3.print();
    
    cm4 = cm1 + cm2; // 隐式调用 operator+(cm1, cm2)
    cm4.print();
    
    cm2 += cm1;      // 隐式调用 cm2.operator+=(cm1)
    cm2.print();
    
    return 0;
}