#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int chess[6][6] = {0};
    string col[6] = {"A", "B", "C", "D", "E", "F"};
    string result = "Valid";
    int last[2] = {-1, -1};
    int start[2];
    for (int i = 0; i < 36; i++) {
        string location;
        cin >> location;
        int c, r;
        c = distance(col, find(col, col+6, location.substr(0, 1)));
        r = stoi(location.substr(1, 1))-1;
        if (last[0] == -1 && last[1] == -1) {
            last[0] = c;
            last[1] = r;
            start[0] = c;
            start[1] = r;
        } else {
            int diff_c = abs(last[0] - c);
            int diff_r = abs(last[1] - r);
            if ((diff_c == 2 && diff_r == 1) || (diff_c == 1 && diff_r == 2)) {
                last[0] = c;
                last[1] = r;
            } else {
                result = "Invalid";
                break;
            }
        }
        if (chess[c][r] != 0){
            result = "Invalid";
            break;
        } else {
            chess[c][r] = 1;
        }
        if (i == 35) {
            int diff_c = abs(start[0] - c);
            int diff_r = abs(start[1] - r);
            if ((diff_c != 2 || diff_r != 1) && (diff_c != 1 || diff_r != 2)) {
                result = "Invalid";
                break;
            }
        }
    }
    cout << result << endl;
}