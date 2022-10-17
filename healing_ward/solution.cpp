#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int c = 0; c < tc; c++) {
        long long int safe_zone_size, game_time;
        long long int dead_body_count, healing_ward_count;
        cin >> safe_zone_size >> game_time;
        cin >> dead_body_count >> healing_ward_count;
        long long int ** safe_zone = new long long int* [safe_zone_size];
        long long int dmg_diff = healing_ward_count-dead_body_count;
        for (int i = 0; i < safe_zone_size; i++) {
            safe_zone[i] = new long long int[safe_zone_size] {0, };
        }
        vector<pair<int, int>> dead_bodys;
        long long int grow_finish_time = 0;
        for (int i = 0; i < dead_body_count; i++) {
            long long int row, col;
            cin >> row >> col;
            dead_bodys.push_back(make_pair(row, col));
            if (max({row, col, safe_zone_size-row, safe_zone_size-col}) > grow_finish_time) {
                grow_finish_time = max({row, col, safe_zone_size-row, safe_zone_size-col});
            }
        }

        vector<pair<int, int>> healing_wards;
        for (int i = 0; i < healing_ward_count; i++) {
            long long int row, col;
            cin >> row >> col;
            healing_wards.push_back(make_pair(row, col));
            if (max({row + col, safe_zone_size-row + col, safe_zone_size*2-row + col}) > grow_finish_time) {
                grow_finish_time = max({row + col, safe_zone_size-row + col, safe_zone_size*2-row + col});
            }
        }

        long long int left_time;
        if (grow_finish_time > game_time) {
            grow_finish_time = game_time;
            left_time = 0;
        } else {
            left_time = game_time - grow_finish_time;
        }

        for (int dead_body_index = 0; dead_body_index < dead_body_count; dead_body_index++) {
            for (int current_time = 1; current_time <= grow_finish_time; current_time++) {
                for (int i = dead_bodys[dead_body_index].first-current_time; i <= dead_bodys[dead_body_index].first+current_time; i++) {
                    for (int j = dead_bodys[dead_body_index].second-current_time; j <= dead_bodys[dead_body_index].second+current_time; j++) {
                        if (i >= 0 && i < safe_zone_size && j >= 0 && j < safe_zone_size) {
                            safe_zone[i][j] -= 1;
                        }
                    }
                }
            }
        }

        for (int healing_ward_index = 0; healing_ward_index < healing_ward_count; healing_ward_index++) {
            for (int current_time = 1; current_time <= grow_finish_time; current_time++) {
                for (int i = healing_wards[healing_ward_index].first-current_time; i <= healing_wards[healing_ward_index].first+current_time; i++) {
                    for (int j = healing_wards[healing_ward_index].second-current_time; j <=healing_wards[healing_ward_index].second+current_time; j++) {
                        if (i >= 0 && i < safe_zone_size && j >= 0 && j < safe_zone_size && (abs(healing_wards[healing_ward_index].first-i) + abs(healing_wards[healing_ward_index].second-j) <= current_time)) {
                            safe_zone[i][j] += 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < safe_zone_size; i++) {
            for (int j = 0; j < safe_zone_size; j++) {
                safe_zone[i][j] += (dmg_diff*left_time);
            }
        }

        for (int i = 0; i < safe_zone_size; i++) {
            for (int j = 0; j < safe_zone_size; j++) {
                cout << safe_zone[i][j] << " ";
            }
            cout << endl;
        }
    }
}