#include <iostream>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int c = 0; c < testCase; c++) {
        int n;
        int fib_one[41];
        int fib_zero[41];
        fib_one[0] = 0;
        fib_zero[0] = 1;
        fib_one[1] = 1;
        fib_zero[1] = 0;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            fib_one[i] = fib_one[i-2] + fib_one[i-1];
            fib_zero[i] = fib_zero[i-2] + fib_zero[i-1];
        }
        cout << fib_zero[n] << " " << fib_one[n] << endl;
    }
}