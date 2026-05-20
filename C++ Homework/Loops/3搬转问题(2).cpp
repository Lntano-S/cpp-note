#include <iostream>

int main(void) {
    /*
    x + y + z = n
    4x + 3y + z / 2 = n
        -> 7x + 5y = n
    */
    int n;
    std::cin >> n;

    for (int male = 0; male <= (n / 7); male++) {
        if ((n - 7 * male) % 5 == 0) {
            int female = (n - 7 * male) / 5;
            int children = n - male - female;
            std::cout << male << " " << female << " " << children << std::endl;
        }
    }

    return 0;
}