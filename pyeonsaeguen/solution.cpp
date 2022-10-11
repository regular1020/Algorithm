#include <iostream>

using namespace std;

int manhathan(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

int main() {
    int tc;
    cin >> tc;
    for (int c = 0; c < tc; c++) {
        int map_size;
        int convenience_count;
        cin >> map_size >> convenience_count;
        int ** conv_map = new int* [map_size] {0};
        for (int i = 0; i < map_size; i++) {
            conv_map[i] = new int[map_size] {0};
        }
        for (int i = 0; i < convenience_count; i++) {
            int col, row;
            cin >> row >> col;
            conv_map[row][col] = -99999;
            for (int j = 0; j < map_size; j++) {
                for (int k = 0; k < map_size; k++) {
                    if (manhathan(row, col, j, k) <= 10) {
                        conv_map[j][k] = conv_map[j][k] + 1;
                    }
                    if (manhathan(row, col, j, k) <= 3) {
                        conv_map[j][k] = conv_map[j][k] + 2;
                    }
                }
            }
        }
        int max_row = 0;
        int max_col = 0;
        int max_score = 0;
        for (int i = 0; i < map_size; i++) {
            for (int j = 0; j < map_size; j++) {
                if (conv_map[i][j] > max_score){
                    max_col = j;
                    max_row = i;
                    max_score = conv_map[i][j];
                }
            }
        }
        cout << max_row << " " << max_col << " " << max_score << endl;
    }
}