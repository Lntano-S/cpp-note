#include <iostream>

int main(void) {
    int month;

    std::cin >> month;

    switch (month) {
        case 3:
        case 4:
        case 5:
            std::cout << "Spring" << std::endl;
            break;
        case 6:
        case 7:
        case 8:
            std::cout << "Summer" << std::endl;
            break;
        case 9:
        case 10:
        case 11:
            std::cout << "Autumn" << std::endl;
            break;
        case 12:
        case 1:
        case 2:
            std::cout << "Winter" << std::endl;
            break;
    }
}