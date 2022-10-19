#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int wine_count;
    cin >> wine_count;
    int* wine = new int[wine_count];
    int* dp = new int[wine_count];
    for (int i = 0; i < wine_count; i++) {
        cin >> wine[i];
    }
    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max({wine[0]+wine[1], wine[0]+wine[2], wine[1]+wine[2]});
    for (int i = 3; i < wine_count; i++) {
        dp[i] = max({dp[i-3] + wine[i-1] + wine[i], dp[i-2] + wine[i], dp[i-1]});
    }
    cout << dp[wine_count-1] << endl;
} 