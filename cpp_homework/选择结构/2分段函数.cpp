#include <iostream>
#include <iomanip>

double func(double x) {
    if (x > 25) {
        return x + 25;
    } else if (x == 25.0) {
        return 20.;
    } else {
        return 3 * x;
    }
}

int main(void) {
    double x;
    std::cin >> x;

    std::cout << "f(" << x << ")=" << func(x) << std::endl;

    return 0;
}