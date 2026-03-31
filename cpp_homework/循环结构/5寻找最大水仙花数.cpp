#include <iostream>
#include <cmath>

int main(void) {
    int m;
    std::cin >> m;

    // 如果 m 大于 999，就把上限锁死在 999，因为只有三位数才有水仙花数
    if (m > 999) {
        m = 999;
    }

    bool found = false;

    for (int i = m; i >= 100; i--) {
        int digit_1 = i % 10;
        int digit_2 = (i / 10) % 10;
        int digit_3 = i / 100; // 现在这里最多只会被 999 除以 100，安全了

        if (pow(digit_1, 3) + pow(digit_2, 3) + pow(digit_3, 3) == i) {
            std::cout << i << std::endl;
            found = true;
            break;
        } 
    }   

    if (!found) {
        std::cout << "no" << std::endl;
    }

    return 0;
}