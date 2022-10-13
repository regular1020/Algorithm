#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int c = 0; c < tc; c++) {
        string electric_wave;
        cin >> electric_wave;
        if (regex_match(electric_wave, regex("(100+1+|01)+"))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}