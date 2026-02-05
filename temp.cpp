#include <iostream>
#include <vector>

void show_menu() {
	std::cout << "1.加 2.减 3.除 4.乘" << std::endl;
}

double add(double a, double b) {
	return a + b;
}

double substract(double a, double b) {
	return a - b;
}

double multiply(double a, double b)  {
	return a * b;
}

double divide(double a, double b) {
	if (b != 0) {
		return a / b;
	} else if (b == 0) {
		std::cout << "除数不能为0,请重新输入" << std::endl;
		return 0;
	}
}

int main(void) {
	int choice;
	int a;
	int b;
	
	show_menu();
	std::cout << "请输入你的选择：" << std::endl;
	std::cin >> choice;
	std::cout << "请分别输入两个实数" << std::endl;
	std::cin >> a;
	std::cin >> b;
	
	switch (choice) {
		case 1:
			std::cout << "两数之和为" << add(a, b) << std::endl;
			break;
			
		case 2:
			std::cout << "两数之差为" << substract(a, b) << std::endl;
			break;
			
		case 3:
			std::cout << "两数之商为" << divide(a, b) << std::endl;
			break;
			
		case 4:
			std::cout << "两数之积为" << multiply(a, b) << std::endl;
			break;
	}
	return 0;
}