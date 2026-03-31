#include <iostream>

int main(void) {
    int m, n;
    int x = 0, y = 0;

    std::cin >> m >> n;

    for (int i = m; i <= n; i++) {
        if (i % 2 != 0) y += i * i * i;
        else x += i * i;
    }

    std::cout << x << " " << y << std::endl;

    return 0;
}