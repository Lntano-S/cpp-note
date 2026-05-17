#include <iostream>

using namespace std;

void sum_diff(float op1, float op2, float *psum, float *pdiff ) {
    *psum = op1 + op2;
    *pdiff = op1 - op2;
}

int main(void) {
    float a, b, sum, diff;

    cin >> a >> b;
    sum_diff(a, b, &sum, &diff);
    cout << "The sum is " << sum << endl;
    cout << "The diff is " << diff << endl;
    
    return 0;   
}