#include <iostream>

using namespace std;

float fun(int a[], int n, int *max, int *min) {
    *max = a[0];
    *min = a[0];
    float total = 0.0;
    
    for (int i = 0; i < n; i++) {
        int current = a[i];
        total += a[i];

        if (current > *max) { *max = current; }
        else if (current < *min) { *min = current; } 
    }

    return total / n;
}

int main(void) {
    int x[10], i, m, n;
    float p;

    for(i = 0; i < 10; i++) {
        cin >> x[i];
    }
    p = fun(x, 10, &m, &n);
    cout << "max=" << m << ",min=" << n << ",average=" << p << endl;
    
    return 0;
}