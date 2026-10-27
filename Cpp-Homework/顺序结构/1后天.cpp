#include <iostream>

int main(void) {
    int D;
    std::cin >> D;

    int result = D + 2;
    if (result % 7 == 0) {
        std::cout << result;
    } else {
        std::cout << result % 7;
    }

    return 0;
}