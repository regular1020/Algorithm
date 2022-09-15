#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int dp[90][2];
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
    }
    cout << dp[n-1][0] + dp[n-1][1] << endl;
}