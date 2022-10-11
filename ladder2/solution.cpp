#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int c = 0; c < tc; c++) {
        int start_point_count, ladder_size, destination;
        cin >> start_point_count >> ladder_size >> destination;
        char ** ladder_map = new char*[ladder_size];
        for (int i = 0; i < ladder_size; i++) {
            ladder_map[i] = new char[start_point_count*2-1];
            cin >> ladder_map[i];
        }
        int current_y = ladder_size-1;
        int current_x1 = destination*2-2;
        int current_x2 = destination*2-2;
        int current_x3 = destination*2-2;
        while (current_y >= 0) {
            if (ladder_map[current_y][current_x2] == '?') {
                if (current_x1-2 >= 0) {
                    current_x1 = current_x1 - 2;
                }
                if (current_x3+2 <= start_point_count*2-2) {
                    current_x3 = current_x3 + 2;
                }
            }else {
                bool is_move = false;
                if (current_x1-2 >= 0) {
                    if (ladder_map[current_y][current_x1-1] == '+') {
                        current_x1 = current_x1 - 2;
                        is_move = true;
                    }
                }
                if (!is_move) {
                    if (current_x1+2 <= start_point_count*2-2) {
                        if (ladder_map[current_y][current_x1+1] == '+') {
                            current_x1 = current_x1 + 2;
                        }
                    }
                }

                is_move = false;
                if (current_x2-2 >= 0) {
                    if (ladder_map[current_y][current_x2-1] == '+') {
                        current_x2 = current_x2 - 2;
                        is_move = true;
                    }
                }
                if (!is_move) {
                    if (current_x2+2 <= start_point_count*2-2) {
                        if (ladder_map[current_y][current_x2+1] == '+') {
                            current_x2 = current_x2 + 2;
                        }
                    }
                }

                is_move = false;
                if (current_x3-2 >= 0) {
                    if (ladder_map[current_y][current_x3-1] == '+') {
                        current_x3 = current_x3 - 2;
                        is_move = true;
                    }
                }
                if (!is_move) {
                    if (current_x3+2 <= start_point_count*2-2) {
                        if (ladder_map[current_y][current_x3+1] == '+') {
                            current_x3 = current_x3 + 2;
                        }
                    }
                }
            }
            current_y = current_y - 1;
        }

        set<int> s;
        vector<int> v;
        s.insert(int((current_x1+2)/2));
        s.insert(int((current_x2+2)/2));
        s.insert(int((current_x3+2)/2));
        copy(s.begin(), s.end(), back_inserter(v));
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}