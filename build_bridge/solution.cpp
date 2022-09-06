#include <iostream>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int c = 0; c < testCase; c++) {
        int n, m;
        cin >> n >> m;
        int bridge[31][31];
        for (int i = 1; i <= 30; i++) {
            for (int j = 1; j <= 30; j++) {
                bridge[i][j] = 0;
            }
        }
        for (int i = 1; i <= 30; i++) {
            bridge[i][i] = 1;
            bridge[1][i] = i;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i+1; j <= m; j++) {
                bridge[i][j] = bridge[i][j-1] + bridge[i-1][j-1];
            }
        }
        cout << bridge[n][m] << endl;
    }
}