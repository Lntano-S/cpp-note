#include <iostream>
#include <vector>

// 模板，自动识别类型
template<typename T, typename It>

// 实现 Python 中的 pop() 函数
T pop_out(std::vector<T> &vec, It it) {
    T temp = *it;
    vec.erase(it);
    return temp;
}

// 主函数
int main(void) {
    std::vector<int> nums1 = {3, 4, 5, 6, 7};
    std::vector<double> nums2 = {1.1, 5.6, 6.4, 3.9, 4.2};
    
    // 使用 pop_out 函数
    auto erased_num1 = pop_out(nums1, nums1.begin() + 2);
    auto erased_num2 = pop_out(nums2, nums2.end() - 2);

    std::cout << erased_num1 << std::endl;
    for (int num : nums1) {
        std::cout << num << " ";
    }
    
    std::cout << std::endl;

    std::cout << erased_num2 << std::endl;
    for (double num : nums2) {
        std::cout << num << " ";
    }
}
