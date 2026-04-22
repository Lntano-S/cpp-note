#include <iostream>

using namespace std;

class Point {
public:
    Point(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
        count++;
    }

    // 拷贝构造函数：传已有对象的地址
    Point(const Point& p) : x(p.x), y(p.y) {
        count++;
    }

    int getX() {return x;}
    int getY() {return y;}

    static void showCount();


private:
    int x, y;
    static int count;
};

int Point::count = 0;

void Point::showCount() {
    cout << count << "\n";
}

int main(void)
{
   int x, y;
   cin >> x >> y;

   Point::showCount();
   Point a(x, y);
   cout << "Point A: " << a.getX() << "," << a.getY() << endl;
   Point::showCount(); 

   Point b(a);
   cout << "Point B: " << b.getX() << "," << b.getY() << endl;
   Point::showCount();

   Point c;
   cout << "Point C: " << c.getX() << "," << c.getY() << endl;
   Point::showCount();

   Point d(x);
   cout << "Point D: " << d.getX() << "," << d.getY() << endl;
   Point::showCount();
   cout << "How many points now?";
   Point::showCount();
   return 0;
}