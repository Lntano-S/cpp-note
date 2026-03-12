#include <iostream>
#include <vector>
#include <algorithm>

/* 
定义一个指针函数，返回类型：布尔值
               *：表示这是一个指针
               int：表示输入值的类型

*/
using ConditionFunc = bool (*)(int);

// 数组过滤函数
std::vector<int> filterArray(const std::vector<int>& arr, ConditionFunc condition) {
    std::vector<int> result;

    for (int num : arr) {
        // 利用指针函数返回的布尔值进行 if 条件判断
        if (condition(num)) {
            result.push_back(num);
        }
    }

    return result;
}

int main(void) {
    std::vector<int> numbers = {3, 16, 5, 6, 17, 8, 14, 18};

    std::vector<int> evens = filterArray(numbers, [](int n) -> bool {
        return n % 2 == 0;
    });

    std::vector<int> bignumbers = filterArray(numbers, [](int m) -> bool {
        return m > 10;
    });

    std::sort(numbers.begin(), numbers.end(), [](int a, int b) -> bool {
        return a > b;
    });

    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}