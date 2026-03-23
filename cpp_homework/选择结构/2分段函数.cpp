#include <iostream>

double func(double x) {
    if (x > 25) {
        return x + 25;
    } else if (x == 25) {
        return 25;
    } else {
        return 3 * x;
    }
}

int main(void) {
    double x;
    std::cin >> x;

    printf("f(%.1lf)=%.1lf", x, func(x));

    return 0;
}