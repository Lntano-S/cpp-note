#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double image;

public:
    Complex(double _real = 0.0, double _image = 0.0)
        : real(_real), image(_image) {}

    Complex neg() {
        return Complex(-real, -image);
    }

    Complex add(const Complex& other) {
        return Complex(
            this->real + other.real, 
            this->image + other.image
        );
    }

    Complex add_assignment(const Complex& other) {
        this->real += other.real;
        this->image += other.image;

        return Complex(this->real, this->image);
    }

    void print() {
        cout << this->real << " + " << this->image << "i" << "\n";
    }

};

int main(void) {
    Complex cm1(1.5,-2.3),cm2(3.3,8.7),cm3,cm4;
    cm3 = cm1.neg();
    cm3.print();
    cm4 = cm1.add(cm2);
    cm4.print();
    cm2.add_assignment(cm1);
    cm2.print();
    return 0;
}