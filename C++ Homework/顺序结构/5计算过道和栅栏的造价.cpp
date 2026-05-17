#include <iostream>
#include <cmath>

int main(void) {
    double r;
    const double pi = 3.14159;

    std::cin >> r;

    double fence = 2 * pi * (r + 3);
    double corridor = pi * (pow(r + 3, 2) - pow(r, 2));

    int pfence = round(fence * 55);
    int pcorridor = round(corridor * 40);
    
    printf("%d %d", pcorridor, pfence);

    return 0;
}