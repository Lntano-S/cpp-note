#include <iostream>

int main(void) {
    int year, month;
    std::cin >> year >> month;

    if (year < 0 || year > 10000 || month < 1 || month > 12) {
        std::cout << "Error!" << std::endl;
        return 0;
    }

    // 2. 定义平年每月天数数组 (下标 0 空置，让下标 1 对应 1 月)
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool is_leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    if (month == 2 && (is_leap)) {
        std::cout << 29;
    } else {
        std::cout << days[month];
    }

    return 0;
}