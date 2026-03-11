#include <iostream>
#include <vector>

using ConditionFunc = bool (*)(int);

std::vector<int> filterArray(const std::vector<int>& arr, ConditionFunc condition) {
    std::vector<int> result;
    for (int num : arr) {
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

    std::sort


    return 0;
}