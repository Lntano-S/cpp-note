#include <iostream>
#include <cmath>

int main(void) {
    double a, b, c;

    std::cin >> a >> b >> c;

    double sol_1 = (- b + sqrt(b * b - 4 * a * c)) / (a * 2);
    double sol_2 = (- b - sqrt(b * b - 4 * a * c)) / (a * 2);

    printf("%.2lf\n%.2lf\n", sol_1, sol_2);

    return 0;
}