#include <iostream>

int main(void) {
	int secret = 42;
	int guess;
	int count = 0;
	
	while (true) {
		std::cout << "请输入你的猜测(1-100): " << std::endl;
		std::cin >> guess;
		count++;
		
		if (guess > secret) {
			std::cout << "太大了" << std::endl;
		} else if (guess < secret) {
			std::cout << "太小了" << std::endl;
		} else {
			std::cout << "恭喜你，仅用 " << count << " 次就猜出答案！";
			break;
		}
	}
	return 0;
}