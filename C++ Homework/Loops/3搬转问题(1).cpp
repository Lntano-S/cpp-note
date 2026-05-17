#include <iostream>

int main(void) {   
    int n;
    std::cin >> n;
    
    int male = 0;
    int female = 0;
    int children = 0;

    for (int a = 0; a <= (n / 4); a++) {
        for (int b = 0; b <= (n / 3); b++) {
            male = a;
            female = b;
            children = n - a - b;
            if ((children % 2 == 0) && (8 * male + 6 * female + children == 2 * n)) {
                std::cout << male << " " << female << " " << children << std::endl;
            }
        }
    }

    return 0;
}