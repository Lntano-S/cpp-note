#include  <iostream>
#define PI 3.14159
using namespace std;

// 基类 Shape
class Shape {
public:
    Shape() {}
    
    // Shape的输出
    void print() {
        cout << "Shape" << endl;
    }
    
    double getArea() {
        return 0;
    }
    
    double getPerimeter() {
        return 0;
    }
};

// 派生类 Rectangle
class Rectangle : public Shape {
private:
    double height;
    double width;
public:
    // 根据 main 函数中的 Rectangle recObj(7.2,3.5) 和样例输出 Width=3.5,Height=7.2 
    // 可以看出第一个参数是高，第二个参数是宽
    Rectangle(double h, double w) {
        height = h;
        width = w;
    }
    
    void print() {
        cout << "Rectangle: Width=" << width << ",Height=" << height << endl;
    }
    
    double getArea() {
        return height * width;
    }
    
    double getPerimeter() {
        return 2 * (height + width);
    }
};

// 派生类 Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    
    void print() {
        cout << "Circle: R=" << radius << endl;
    }
    
    double getArea() {
        return PI * radius * radius;
    }
    
    double getPerimeter() {
        return 2 * PI * radius;
    }
};

int main()
{
    Rectangle recObj(7.2,3.5);
    recObj.print();
    cout<<"Area="<<recObj.getArea()<<" Perimeter="<<recObj.getPerimeter()<<endl;

    Circle circleObj(2.3);
    circleObj.print();
    cout<<"Area="<<circleObj.getArea()<<" Perimeter="<<circleObj.getPerimeter()<<endl;

    Shape shapeObj;
    shapeObj.print();
    cout<<"Area="<<shapeObj.getArea()<<" Perimeter="<<shapeObj.getPerimeter()<<endl;
    return 0;
}