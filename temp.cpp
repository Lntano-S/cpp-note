#include <iostream>

int main(void) {
    int x;
    std::cin >> x;

    bool b1 = x % 2 == 0;
    bool b2 = (4 < x) && (x <= 12);

    if (b1 && b2) {
        std::cout << "1 ";
    } else {
        std::cout << "0 ";
    }

    if (b1 || b2) {
        std::cout << "1 ";
    } else {
        std::cout << "0 ";
    }

    if ((b1 && !b2) || (!b1 && b2))  {
        std::cout << "1 ";
    } else {
        std::cout << "0 ";
    }

    if (!b1 && !b2) {
        std::cout << "1 ";
    } else {
        std::cout << "0 ";
    }

    return 0;
}