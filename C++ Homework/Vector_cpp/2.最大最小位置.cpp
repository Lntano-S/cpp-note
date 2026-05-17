#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n = 10;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int min_val = arr[0];
    int max_val = arr[0];
    int min_pos = 0;
    int max_pos = 0;

    for (int j = 1; j < n; j++) {
        int current = arr[j];

        if (current > max_val) {
            max_val = current;
            max_pos = j;
        }

        if (current < min_val) {
            min_val = current;
            min_pos = j;
        }
    }

    cout << "max value " << max_val << " position " << max_pos << "\n"
         << "min value " << min_val << " position " << min_pos << "\n";

    return 0;
}