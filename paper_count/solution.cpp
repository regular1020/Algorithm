#include <iostream>

using namespace std;

int** paper;

int* paper_cut(int y, int x, int n) {
    int number = paper[y][x];
    int* result = new int[3] {0};
    bool check = true;
    if (n == 1) {
        if(number == -1) {
            result[0]++;
        } else if (number == 0) {
            result[1]++;
        } else {
            result[2]++;
        }
        return result;
    }
    for (int i = y; i < y+n; i++) {
        for (int j = x; j < x+n; j++) {
            if(paper[i][j] != number) {
                check = false;
                break;
            }
        }
        if (!check){
            break;
        }
    }
    if (check) {
        if(number == -1) {
            result[0]++;
        } else if (number == 0) {
            result[1]++;
        } else {
            result[2]++;
        }
        return result;
    } else {
        int new_number = n/3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int new_y = y+(i*new_number);
                int new_x = x+(j*new_number);
                int* new_result;
                new_result = paper_cut(new_y, new_x, new_number);
                result[0] = result[0] + new_result[0];
                result[1] = result[1] + new_result[1];
                result[2] = result[2] + new_result[2];
            }
        }
        return result;
    }

}

int main() {
    int n;
    cin >> n;
    paper = new int* [n];
    for (int i = 0; i < n; i++) {
        paper[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    int* result;
    result = paper_cut(0, 0, n);
    cout << result[0] << endl;
    cout << result[1] << endl;
    cout << result[2] << endl;
}