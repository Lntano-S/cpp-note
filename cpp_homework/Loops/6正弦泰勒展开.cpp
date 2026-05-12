#include <iostream>
#include <cmath>

double fact(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}


int main(void) {
    int n;
    double x;
    std::cin >> x >> n;
    double round = 0.0;

    for (int i = 1; i <= n; i++) {
        round += pow(-1.0, i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1);
    }

    printf("%.8lf", round);

    return 0;
}