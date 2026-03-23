#include <cmath>
#include <iostream>

int main(void) {
    double x, y;
    double e = M_E;

    std::cin >> x >> y;

    double result = sqrt(x + 2*y) - pow(e, 3 * x) + fabs(x);
    
    printf("%lf\n", result);

    return 0;
}