#include <iostream>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(void) {
    std::cout << lcm(4, 6) << std::endl;
    return 0;
}