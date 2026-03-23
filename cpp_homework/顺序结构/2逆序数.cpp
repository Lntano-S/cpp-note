#include <iostream>

using namespace std;

int main(void) {
    int num;
    int result = 0;

    cin >> num;
    num = abs(num);

    // 普适地实现逆序
    while (num > 0) {
        int digit = num % 10; // 10取出 num 的个位

        result = result * 10 + digit;

        // 去掉 num 的个位
        num = num / 10;
    }

    std::cout << result << std::endl;

    return 0;
}