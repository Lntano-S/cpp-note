#include <iostream>
#include <vector>
#include <string>

int main(void) {
	std::vector<double> prices;
	double total = 0;
	double max_price = -1;
	double price;
	
	while (true) {
		std::cout << "请输入商品价格（输入 0 或 -1退出）：" << std::endl;
		std::cin >> price;
		
		if (price == 0 || price == -1) {
			break;
		} else if (price > 0) {
			prices.push_back(price);
		}
	}
	

	for (double price: prices) {
		total += price;
		
		if (price > max_price) {
			max_price = price;
		}
	}
	
	std::cout << "====账单====" << std::endl;
	std::cout << "总金额：" << total << " 元" << std::endl;
	std::cout << "平均花费：" << total / prices.size() << " 元" << std::endl;
	std::cout << "单件最大开销：" << max_price << " 元" << std::endl;
	
	return 0;
}