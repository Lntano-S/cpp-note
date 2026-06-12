#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n = 10;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int min_val = 0; // 定义 0 为默认极小值
    int max_val = 0; // 定义 0 为默认极大值
    int min_pos = 0; // 默认位置同样给 0
    int max_pos = 0; 
    
    // 如果采用 0 兜底，然后从头遍历：
    for (int j = 0; j < n; j++) {
        int current = arr[j];
        if (current > max_val) { 
            max_val = current; 
            max_pos = j + 1; // 尝试更新最大值位置（题目要求从 1 开始记数）
        }
        if (current < min_val) { 
            min_val = current; 
            min_pos = j + 1; 
        }
    }

    cout << "max value " << max_val << " position " << max_pos << "\n"
         << "min value " << min_val << " position " << min_pos << "\n";

    return 0;
}