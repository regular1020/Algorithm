#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int r, c, t, filtered_count;
    cin >> r >> c;
    int** img = new int*[r];
    for (int i = 0; i < r; i++) {
        img[i] = new int[c];
        for (int j = 0; j < c; j++) {
            cin >> img[i][j];
        }
    }
    cin >> t;
    filtered_count = 0;
    for (int i = 0; i < r-2; i++) {
        for (int j = 0; j < c-2; j++) {
            int filtered[9] = {img[i][j], img[i][j+1], img[i][j+2], img[i+1][j], img[i+1][j+1], img[i+1][j+2], img[i+2][j], img[i+2][j+1], img[i+2][j+2]};
            sort(filtered, filtered+9);
            if (filtered[4] >= t) {
                filtered_count++;
            }
        }
    }
    cout << filtered_count << endl;
}