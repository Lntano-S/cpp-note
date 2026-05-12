#include <iostream>


int main(void) {
    int year, month;

    std::cin >> year >> month;

    if ((year < 0) || (year > 10000) || (month <= 0) || (month >= 13)) {
        std::cout << "Error!" << std::endl;
        return 0;
    }

        bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                std::cout << 31 << std::endl;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                std::cout << 30 << std::endl;
                break;
            case 2:
                if (is_leap) std::cout << 29;
                else std::cout << 28;
                break;
            default:
                break;
        }

    return 0;
}