#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int c = 0; c < testCase; c++) {
        int start_count, ladder_size, destination;
        cin >> start_count >> ladder_size >> destination;
        char** map = new char* [ladder_size];
        cin.ignore();
        for (int i = 0; i < ladder_size; i++) {
            char* line = new char[start_count*2-1];
            string buffer;
            getline(cin, buffer);
            strcpy(line, buffer.c_str());
            map[i] = line;
        }

        int cur_y = ladder_size-1;
        int cur_x = destination*2-2;

        while (cur_y >= 0) {
            if (cur_x < start_count*2-3){
                if (map[cur_y][cur_x+1] == '+') {
                    cur_x = cur_x + 2;
                }
            } else if (cur_x >= 2) {
                if (map[cur_y][cur_x-1] == '+') {
                    cur_x = cur_x - 2;
                }
            }
            cur_y = cur_y-1;
        }

        cout << (cur_x+2)/2 << endl;
    }
}