//复数类本不需要自定义 拷贝构造函数、赋值函数、析构函数
//本例是为验证构造函数、拷贝构造函数、赋值函数、析构函数的调用时机

#include<iostream>
#include<cmath>
using namespace std;
class Complex
{
public:
    Complex(double r=0,double i=0):real(r),imag(i) 
	{
		cout<<"Constructor :\t"<<this<<"\t";
		print();
	}

    void print() const
    {
        cout<< real <<" + " << imag <<"i\n";
    }

  	Complex& operator= (const Complex & tmp)
	{
   		this->real =  tmp.real;
   		this->imag =  tmp.imag;
   		cout<<"operator= :\t"<<this<<"\t";
		print();
   		return *this;
	}

	Complex(const Complex & tmp)
	{
   		this->real =  tmp.real;
   		this->imag =  tmp.imag;
 		cout<<"cpyConstructor :\t"<<this<<"\t";
		print();
	}
	
	~Complex()
	{
		cout<<"Destructor :\t"<<this<<"\t";
		print();
	}
private:
    double real;
    double imag;
};

void fun1(Complex tmp)
{
	cout<<"fun1"<<endl;
	tmp.print();
}

void fun2(const Complex& tmp)
{
	cout<<"fun2"<<endl;
	tmp.print();
}

Complex fun3()
{
	cout<<"fun3"<<endl;
	Complex tmp(-5,9);
	return tmp;
}

int main()
{
    Complex cm1(1),cm2(2,4),cm3(3,6),cm4(4,8);
	Complex cm5(cm1);
	Complex cm6;
    cm6 = cm2;
	fun1(cm3);
	fun2(cm4);
	fun3();
    return 0;
}