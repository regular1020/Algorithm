#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    int n;
    cin >> a >> b >> n;
    int share;
    int left = a;
    for (int i = 0; i <= n; i++) {
        share = left / b;
        left = left % b;
        left = stoi(to_string(left)+"0");
    }
    cout << share << endl;
}