#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int max_change = 0;

    vector<int> stocks(n);
    for (int i = 0; i < n; i++) {
        cin >> stocks[i];
    }

    for (int j = 0; j < n-1; j++) {
        int current_change = abs(stocks[j+1] - stocks[j]);

        if (current_change > max_change) {
            max_change = current_change;
        }
    }

    cout << max_change << "\n";

    return 0;
}