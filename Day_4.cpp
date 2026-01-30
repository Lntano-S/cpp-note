#include <iostream>
#include <vector>
#include <string>

int main(void) {
    std::vector<double> prices;
    double price;
    double total = 0;
    double max_price = -1;


    while (true) {
        std::cout << "请输入商品价格(输入 -1 或 0 结束): " << std::endl;
        std::cin >> price;

        if (price == -1 or 0) {
            break;
        } else if (price > 0) {
            prices.push_back(price);
        }
    }

    for (double item: prices) {
        total += price;

        if (price > max_price) {
            max_price = price;
        }
    }

    std::cout << "===账单===" << std::endl;
    std::cout << "一共买了" << prices.size() << "件商品。" << std::endl;
    std::cout << "平均花费：" <<  total / prices.size() << "元" << std::endl;
    std::cout << "最贵的一件商品为" << max_price << "元" << std::endl;

    return 0;
}