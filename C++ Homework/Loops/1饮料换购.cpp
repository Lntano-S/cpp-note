#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    int cap = n;
    int drink = n; 

    while (cap >= 3) {
        int new_drink = cap / 3;
        drink += new_drink;
        cap = new_drink + cap % 3;
    }

    std::cout << drink << std::endl;

    return 0;
}