#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* continuous = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> continuous[i];
    }
    int current_sum = 0;
    int max_sum = continuous[0];
    for (int i = 0; i < n; i++) {
        if (continuous[i] >= current_sum && current_sum < 0) {
            current_sum = continuous[i];
        } else {
            current_sum = current_sum + continuous[i];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    cout << max_sum << endl;
}