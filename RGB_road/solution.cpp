#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int house_count;
    cin >> house_count;
    int** color_cost = new int*[house_count];
    int** cost_dp = new int*[house_count];
    for (int i = 0; i < house_count; i++) {
        color_cost[i] = new int[3];
        cost_dp[i] = new int[3] {0};
    }
    for (int i = 0; i < house_count; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> color_cost[i][j];
        }
    }
    cost_dp[0][0] = color_cost[0][0];
    cost_dp[0][1] = color_cost[0][1];
    cost_dp[0][2] = color_cost[0][2];
    for (int i = 1; i < house_count; i++) {
        cost_dp[i][0] = color_cost[i][0] + min(cost_dp[i-1][1], cost_dp[i-1][2]);
        cost_dp[i][1] = color_cost[i][1] + min(cost_dp[i-1][0], cost_dp[i-1][2]);
        cost_dp[i][2] = color_cost[i][2] + min(cost_dp[i-1][1], cost_dp[i-1][0]);
    }
    cout << min({cost_dp[house_count-1][0], cost_dp[house_count-1][1], cost_dp[house_count-1][2]}) << endl;
}