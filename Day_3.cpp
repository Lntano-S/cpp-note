#include <iostream>

int main(void) {
    int guess;
    int count = 0;
    int secret = 42;

    while (true) {
        std::cout << "请输入你的猜测(整数): " << std::endl;
        std::cin >> guess;
        count++;

        if (guess > secret) {
            std::cout << "太大了！" << std::endl;
        } else if (guess < secret) {
            std::cout << "太小了！" << std::endl;
        } else {
            std::cout << "牛逼，你猜对了！" << std::endl;
            break;
        }

    }

    std::cout << "你一共猜了" << count << "次";
    return 0;
}