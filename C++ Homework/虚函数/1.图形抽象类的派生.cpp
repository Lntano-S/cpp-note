#include  <iostream>
#define PI 3.14159
using namespace std;

// 抽象基类 Shape
class Shape
{
public:
    // 声明为纯虚函数，使 Shape 成为抽象类
    virtual void print() = 0;             
    virtual double getArea() = 0;         
    virtual double getPerimeter() = 0;    
    
    // 虚析构函数
    virtual ~Shape() {} 
};

// 派生类 Circle
class Circle : public Shape
{
private:
    double radius; // 半径

public:
    Circle(double r) : radius(r) {}

    void print() override {
        cout << "Circle: R=" << radius << endl;
    }

    double getArea() override {
        return PI * radius * radius;
    }

    double getPerimeter() override {
        return 2 * PI * radius;
    }
};

class Rectangle : public Shape
{
private:
    double height; // 高
    double width;  // 宽

public:
    Rectangle(double h, double w) : height(h), width(w) {}

    void print() override {
        cout << "Rectangle: Width=" << width << ",Height=" << height << endl;
    }

    double getArea() override {
        return width * height;
    }

    double getPerimeter() override {
        return 2 * (width + height);
    }
};

int main()
{
    Rectangle recA(7.2,3.5), recB(7.2,3.5);
    Circle circleA(2.3), circleB(1.5);
    Shape *pShape[4]={&recB, &circleA, &circleB, &recA};
   
    for( int i=0; i<4; i++)
    {
        pShape[i]->print();
        cout<<"Area="<< pShape[i]->getArea()<<" Perimeter="<< pShape[i]->getPerimeter()<<endl;
    }    
    return 0;
}