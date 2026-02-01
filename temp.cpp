#include <iostream>

int main() {
    int choice;
    std::cout << "1. 打游戏\n2. 看电影\n3. 睡觉\n请输入选项: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "启动 Steam..." << std::endl;
            break; // 必须写 break，否则会直接滑到下一个 case
        case 2:
            std::cout << "打开 B站..." << std::endl;
            break;
        case 3:
            std::cout << "晚安玛卡巴卡。" << std::endl;
            break;
        default: // 如果输入的不是1、2、3
            std::cout << "无效选项，你按错了吧？" << std::endl;
            break;
    }

    return 0;
}