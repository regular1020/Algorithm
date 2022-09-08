#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int broken_line, brand;
    cin >> broken_line >> brand;
    int* package = new int[brand];
    int* single = new int[brand];
    int min_package = INT_MAX;
    int min_single = INT_MAX;
    for (int i = 0; i < brand; i++) {
        cin >> package[i] >> single[i];
        if (package[i] < min_package) {
            min_package = package[i];
        }
        if (single[i] < min_single) {
            min_single = single[i];
        }
    }
    int tmp1 = broken_line/6;
    int tmp2 = broken_line%6;
    int result1 = tmp1 * min_package + tmp2*min_single;
    int result2 = (tmp1+1) * min_package;
    int result3 = broken_line*min_single;
    int result = min({result1, result2, result3});
    cout << result << endl;
}