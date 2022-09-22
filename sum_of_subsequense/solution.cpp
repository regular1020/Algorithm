#include <iostream>
#include <algorithm>

using namespace std;

int n, s, sequence[21], subsequence_count;

void cal(int index, int sum) {
    if (index == n) {
        if (sum == s) {
            subsequence_count++;
        }
        return;
    }

    cal(index+1, sum);
    cal(index+1, sum+sequence[index]);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    subsequence_count = 0;
    
    cal(0, 0);
    if(s == 0) {
        subsequence_count--;
    }
    
    cout << subsequence_count << endl;
}