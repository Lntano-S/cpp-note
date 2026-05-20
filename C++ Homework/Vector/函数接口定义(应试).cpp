#include <iostream>
#define MAXN 10     // 若代码中有 MAXN 对象，替换为 10
using namespace std;

// 老式写法：数组作为指针传入（int list[] 或者 int *list 等价）
int search(int list[], int n, int x) 
{
    // 遍历数组查找元素 x
    for (int i = 0; i < n; i++) {
        if (list[i] == x) {
            return i; // 找到了，返回下标
        }
    }
    return -1; // 整个循环都没找到，返回 -1
}

int main()
{
    int i, index, n, x;
    int a[MAXN];

    cin >> n;
    // 保证输入的 n 不超过数组最大容量 MAXN，以防越界
    if (n > MAXN) {
        n = MAXN; 
    }
        
    for (i = 0; i < n; i++)
        cin >> a[i];
        
    cin >> x;
    
    // 调用完善好的 search 函数
    index = search(a, n, x);
    
    if (index != -1)
        cout << "index = " << index << endl;
    else
        cout << "Not found\n";

    return 0;
}