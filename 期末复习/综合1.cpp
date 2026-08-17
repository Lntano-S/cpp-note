#include <iostream>
using namespace std;

// 1. 抽象基类 (Abstract Base Class)
// 包含纯虚函数，通过 "= 0" 声明
class Shape {
public:
    // 虚析构函数：防止多态删除时的资源泄露
    virtual ~Shape() { cout << "Shape 析构" << endl; }
    virtual void print() const = 0; // 纯虚函数
};

class Point : public Shape {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    ~Point() override { cout << "Point 析构" << endl; }

    // 实现基类的纯虚函数
    void print() const override {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    // 2. 成员函数重载 +=：用于修改自身状态
    Point& operator+=(const Point& other) {
        this->x += other.x;
        this->y += other.y;
        return *this; // 返回自身引用支持链式调用
    }

    // 3. 友元函数重载 +：为了对称性，允许处理外部对象
    friend Point operator+(const Point& p1, const Point& p2) {
        return Point(p1.x + p2.x, p1.y + p2.y);
    }

    // 4. 友元函数重载 <<：访问私有成员实现流式输出
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out; // 返回流引用以支持链式输出
    }
};

int main() {
    // 多态：使用基类指针指向派生类对象
    Shape* s = new Point(10, 20);
    s->print();

    Point p1(1, 2), p2(3, 4);
    
    // 使用友元重载 +
    Point p3 = p1 + p2; 
    
    // 使用成员重载 +=
    p1 += p2; 

    // 使用重载 << 进行链式输出
    cout << "p3: " << p3 << ", p1: " << p1 << endl;

    delete s; // 正确调用虚析构函数
    return 0;
}