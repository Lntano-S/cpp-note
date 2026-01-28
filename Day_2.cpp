#include <iostream>

int main(void) {
    int choice;
    int hp = 50;

    std::cout << "你来到了地牢门口，面前有两条路：左边(1)是漆黑的走廊，右边(2)有火光。清输入你的选择：";
    std::cin >> choice;

    switch(choice) {
        case 1:
            std::cout << "你踩到了机关! 掉血50。" << std::endl;
            hp -= 50;

            if (hp > 0) {
                std::cout << "你还活着。";
            } else {
                std::cout << "你死了。";
            }

            break;

        case 2:
            char ch;

            std::cout << "你发现了一个宝箱！打开吗？(y/n)" << std::endl;
            std::cin >> ch;

            switch(ch) {
                case 'y':
                    std::cout << "获得屠龙刀，通关！";
                    break;

                case 'n':
                    std::cout << "你错过了宝藏，但也平安无事。";
                    break;
            }

            break;

        default:
            std::cout << "你在这个世界迷路了，被饿死了。";
            break;
    }  

    return 0;
}