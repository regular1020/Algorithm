#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int c = 0; c < testCase; c++) {
        int load_size;
        cin >> load_size;
        int** map = new int* [load_size];
        int** dp = new int* [load_size];
        for (int i = 0; i < load_size; i++) {
            int* line = new int[5] {0};
            cin >> line[0] >> line[1] >> line[2] >> line[3] >> line[4];
            map[i] = line;
            dp[i] = new int[5] {0};
        }
        int y = load_size-1;
        for (int i = 1; i <= 3; i++) {
            if (map[y][i] != 1) {
                dp[y][i] = map[y][i];
                if (map[y][i-1] == 1){
                    dp[y][i]++;
                }
                if (map[y][i+1] == 1){
                    dp[y][i]++;
                }
            }
        }
        for (y = load_size-2; y >= 0; y--) {
            for (int x = 0; x < 5; x++) {
                if (map[y][x] == 1) {
                    continue;
                }
                dp[y][x] = map[y][x];
                int last1 = 0, last2 = 0, last3 = 0;
                last2 = dp[y+1][x];
                if (x-1 >= 0) {
                    if (map[y][x-1] == 1){
                        dp[y][x]++;
                    }
                    last1 = dp[y+1][x-1];
                }
                if (x+1 < 5) {
                    if (map[y][x+1] == 1){
                        dp[y][x]++;
                    }
                    last3 = dp[y+1][x+1];
                }
                dp[y][x] = dp[y][x] + max({last1, last2, last3});
            }
        }
        cout << max({dp[0][0], dp[0][1], dp[0][2], dp[0][3], dp[0][4]}) << endl;
    }
}