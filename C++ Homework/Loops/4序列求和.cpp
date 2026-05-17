#include <iostream>
#include <cmath>


int main(void) {
    double Y = 0.0;
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        Y += pow(-1.0, i - 1) * (1.0 / i);
    }

    printf("%.2lf", Y);

    return 0;
}