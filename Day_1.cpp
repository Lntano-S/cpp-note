#include <iostream>
#include <string>

int main(void) {
	std::string name;
	double daily_salary;
	int work_days;

	std::cout << "Please enter your name: ";
	std::cin >> name;
	std::cout << "Please enter your age: ";
	std::cin >> daily_salary;
	std::cout << "Please enter your work_days: ";
	std::cin >> work_days;

	std::cout << "=== Salary Slip ===" << std::endl;
	std::cout << "Employee: " << name << std::endl;
	std::cout << "Days worked: " << work_days << std::endl;
	std::cout << "Total Salary: " << work_days * daily_salary << std::endl;
	return 0;
}