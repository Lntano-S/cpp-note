#include<iostream>
using namespace std;

const float PI = 3.14;

class Circle {
public:
    float r;

    Circle(int _r) : r(_r) {
        r = _r;
    }

    float getArea() {
        return PI * r * r;
    }

    float getGirth() {
        return 2 * PI * r;
    }

};



int main(void){
    float r;
    cout << "请输入圆的半径：";
    cin >> r;                                     //从键盘接受半径的值
    Circle c1(r);                            //将值赋值给半径并调用定义好的函数
    cout<<"圆的面积为："<<c1.getArea()<<endl;
    Circle c2(r);
    cout<<"圆的周长为："<<c2.getGirth()<<endl;

    return 0;
}