#include <iostream>

using namespace std;

class Rectangle {
public:
    Rectangle(void);
    Rectangle(float length, float width);
    ~Rectangle(void);

    float getArea();
    float getGirth();

private:
    float mLength;
    float mWidth;
};

Rectangle::Rectangle() : mLength(0.0), mWidth(0.0) {} 

Rectangle::Rectangle(float len, float wid) : mLength(len), mWidth(wid) {}

Rectangle::~Rectangle() {}

float Rectangle::getArea() {
    return mLength * mWidth;
}

float Rectangle::getGirth() {
    return (mLength + mWidth) * 2;
}



int main(void) {
    int len, wid;
    cout << "Input the length and Width: ";
    cin >> len >> wid;

    Rectangle rec(len, wid);

    cout << "The Area is: " << rec.getArea() << "\n"
         << "The Premeter: " << rec.getGirth() << "\n";

    return 0;
}