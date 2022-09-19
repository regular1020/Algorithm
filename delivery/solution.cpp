#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int c = 0; c < testCase; c++) {
        int city_count, load_count, cargo_a, cargo_b;
        cin >> city_count >> load_count >> cargo_a >> cargo_b;
        int** map = new int* [city_count+1];
        for (int i = 0; i <= city_count; i++) {
            map[i] = new int[city_count+1] {0};
        }
        for (int i = 0; i < load_count; i++) {
            int a, b, load; 
            cin >> a >> b >> load;
            if (map[a][b] < load) {
                map[a][b] = load;
                map[b][a] = load;
            }
        }
        bool* visited = new bool[city_count+1] {false};
        int* max_load = new int[city_count+1] {0};
        for (int i = 1; i <= city_count; i++) {
            max_load[i] = map[cargo_a][i];
        }
        max_load[cargo_a] = 0;
        visited[cargo_a] = true;

        for (int i = 0; i < city_count-1; i++) {
            int selected, max_selected;
            max_selected = 0;
            for (int i = 1; i <= city_count; i++) {
                if (visited[i] == true) {
                    continue;
                }
                if (max_load[i] > max_selected) {
                    max_selected = max_load[i];
                    selected = i;
                }
            }

            visited[selected] = true;
            for (int i = 1; i<= city_count; i++) {
                if (visited[i] == true) {
                    continue;
                }
                if (max_load[i] < min(max_load[selected], map[selected][i])) {
                    max_load[i] = min(max_load[selected], map[selected][i]);
                }
            }
        }
        cout << max_load[cargo_b] << endl;
    }
}