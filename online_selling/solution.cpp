#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int eggs, potential_customer;
    cin >> eggs >> potential_customer;
    int* willingness_pay = new int[potential_customer];
    for (int i = 0; i < potential_customer; i++) {
        cin >> willingness_pay[i];
    }
    sort(willingness_pay, willingness_pay+potential_customer);
    int max_income = 0;
    int max_price = 0;
    for (int i = 0; i < potential_customer; i++) {
        int expected_buyer = potential_customer-i;
        int expected_income;
        if (expected_buyer < eggs) {
            expected_income = willingness_pay[i] * expected_buyer;
        } else {
            expected_income = willingness_pay[i] * eggs;
        }
        if (expected_income > max_income) {
            max_income = expected_income;
            max_price = willingness_pay[i];
        }
    }
    cout << max_price << " " << max_income << endl;
}