#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> reversed = arr;
    reverse(reversed.begin(), reversed.end());
    
    for (int i = 0; i < n; i++) {
        cout << reversed[i] << " ";
    }

    return 0;
}