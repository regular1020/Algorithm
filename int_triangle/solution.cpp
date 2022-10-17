#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int triangle_size;
    cin >> triangle_size;
    int ** triangle_map = new int * [triangle_size];
    int ** dp = new int * [triangle_size];
    for (int i = 0; i < triangle_size; i++) {
        triangle_map[i] = new int[i+1] {0, };
        dp[i] = new int[i+1] {0, };
    }
    for (int i = 0; i < triangle_size; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle_map[i][j];
        }
    }

    dp[0][0] = triangle_map[0][0];
    for (int i = 1; i < triangle_size; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + triangle_map[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + triangle_map[i][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle_map[i][j];
            }
        }
    }

    int max_element = 0;
    for (int i = 0; i < triangle_size; i++) {
        if (dp[triangle_size-1][i] > max_element) {
            max_element = dp[triangle_size-1][i];
        }
    }

    cout << max_element << endl;
}