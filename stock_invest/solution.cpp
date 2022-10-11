#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int c = 0; c < testCase; c++) {
        int day_count;
        cin >> day_count;
        unsigned long long int * stock_market = new unsigned long long int[day_count];
        for (int i = 0; i < day_count; i++) {
            cin >> stock_market[i];
        }
        unsigned long long int high_point = stock_market[day_count-1];
        unsigned long long int income = 0;
        for (int i = day_count-2; i >= 0; i--) {
            if (stock_market[i] > high_point) {
                high_point = stock_market[i];
            } else {
                income += (high_point-stock_market[i]);
            }
        }
        cout << income << endl;
    }
}