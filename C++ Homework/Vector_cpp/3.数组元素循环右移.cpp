#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    M = M % N;

    vector<int> front(arr.begin() + (N-M), arr.end());
    vector<int> behind(arr.begin(), arr.begin() + (N-M));
    front.insert(front.end(), behind.begin(), behind.end());

    for (int j = 0; j < N; j++) {
        cout << front[j] << " ";
    }

    return 0;
}


/*

#include <algorithm> // 引入算法库

// ...
M = M % N;
// rotate 函数接受三个参数：起始位置，新的起始位置（旋转点），结束位置
std::rotate(arr.begin(), arr.begin() + (N - M), arr.end());

*/