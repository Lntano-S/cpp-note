#include <iostream>
#include <iomanip>
using namespace std;

// 基类 Point
class Point {
private:
    float x, y;
public:
    Point(float x, float y) : x(x), y(y) {
        cout << "Point constructor called" << endl;
    }
    ~Point() {
        cout << "Point destructor called" << endl;
    }
};

// 派生类 Circle
class Circle : public Point {
private:
    float r;
public:
    Circle(float x, float y, float r) : Point(x, y), r(r) {
        cout << "Circle constructor called" << endl;
    }
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }
    
    // 求周长的函数
    float getCircumference() {
        return 2 * 3.14f * r;  // 根据样例输出18.84推断，圆周率取 3.14
    }
};

int main(void) {
    float x, y, r;
    cin >> x >> y >> r;
    Circle c(x, y, r);
    cout << fixed << setprecision(2) << c.getCircumference() << endl;
    return 0;
}