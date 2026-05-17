#include <iostream>
#include <vector>

using namespace std;

int search(const vector<int>& a, int x) {
    for (int i = 0; i < a.size(); i++){
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, x;
    
    cin >> n;
    
    // 2. 使用 vector，大小直接由变量 n 决定，不再需要什么定死的 MAXN
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cin >> x;
    
    // 3. 变量随用随定义，直接把返回结果给 index
    int index = search(a, x);
    
    if (index != -1)
        cout << "index = " << index << endl;
    else
        cout << "Not found\n";

    return 0;
}