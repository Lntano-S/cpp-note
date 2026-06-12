#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
public:
    Complex(double r=0,double i=0);
    void print() const;
    double real( ) const;//读实部
    double imag( ) const;//读虚部
    void real(double r); //写实部
    void imag(double i); //写虚部
    Complex& add_assignment(const Complex &cm);  //复数累加
    Complex add(const Complex &cm2); //复数和
private:
    double re ; //实部
    double im; //虚部
};

Complex::Complex(double r,double i):re(r),im(i)
{
}

void Complex::print() const
{
    if(fabs(im)<1e-6)
        cout<<re<<endl;
    else if(im>0)
        cout<<re<<"+"<<im<<"i"<<endl;
    else
        cout<<re<<"-"<<fabs(im)<<"i"<<endl;
}

double Complex::real() const//读实部
{
    return re;
}

void Complex::real(double r)//写实部
{
    re=r;
}

double Complex::imag() const//读虚部
{
    return im;
}

void Complex::imag(double i)//写虚部
{
    im=i;
}

Complex& Complex::add_assignment(const Complex &cm)  // 复数累加+=；返回当前对象的引用，以实现本函数的级联调用
{
    re+=cm.re;
    im+=cm.im;
    return *this;
}

Complex Complex::add(const Complex &cm2)  //复数和+
{
    return Complex(re + cm2.re,im + cm2.im);
}

int main()
{
    Complex cm1(1,2), cm2(3,-8), cm3;
    cm3.real(-1);
    cm3.imag(cm1.imag());
    cm1.add_assignment(cm2.add_assignment(cm3)); //函数的级联调用
    cout << "cm1,cm2,cm3 are: \n" ;
    cm1.print();
    cm2.print();
    cm3.print();

    Complex cm4;
    cm4=cm1.add(cm3);
    cout << "cm4 is: \n" ;
    cm4.print();
    return 0;
}