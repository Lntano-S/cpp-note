#include <iostream>

using namespace std;

int get_reverse(int x) {
    int reverse = 0;
    while (x) {
        int digit = x % 10;
        reverse = reverse * 10 + digit;
        x /= 10;
    }
    return reverse;
}


bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }

    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (is_prime(i) && is_prime(get_reverse(i))) {
            cout << i << endl;
        }
    }

    return 0;
}
