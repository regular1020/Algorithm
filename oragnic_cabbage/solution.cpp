#include <iostream>
#include <queue>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int c = 0; c < testCase; c++) {
        int m, n, cabbage_count;
        cin >> m >> n >> cabbage_count;
        int** field = new int* [n];
        for (int i = 0; i < n; i++) {
            field[i] = new int[m] {0};
        }
        for (int i = 0; i < cabbage_count; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }
        int earthworm_count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == 1){
                    earthworm_count++;
                    queue<pair<int, int>> q;
                    pair <int, int> tmp = make_pair(i, j);
                    q.push(tmp);
                    field[i][j] = 2;
                    while (!q.empty()) {
                        int x, y;
                        y = q.front().first;
                        x = q.front().second;
                        if (y-1 >= 0) {
                            if (field[y-1][x] == 1){
                                pair <int, int> tmp = make_pair(y-1, x);
                                q.push(tmp);
                                field[y-1][x] = 2;
                            }
                        }
                        if (x-1 >= 0) {
                            if (field[y][x-1] == 1) {
                                pair <int, int> tmp = make_pair(y, x-1);
                                q.push(tmp);
                                field[y][x-1] = 2;
                            }
                        }
                        if (y+1 < n) {
                            if (field[y+1][x] == 1) {
                                pair <int, int> tmp = make_pair(y+1, x);
                                q.push(tmp);
                                field[y+1][x] = 2;
                            }
                        }
                        if (x+1 < m) {
                            if (field[y][x+1] == 1) {
                                pair <int, int> tmp = make_pair(y, x+1);
                                q.push(tmp);
                                field[y][x+1] = 2;
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        cout << earthworm_count << endl;
    }
}