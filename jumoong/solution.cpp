#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int* materials = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> materials[i];
    }
    sort(materials, materials+n);
    int start, end, armmer_count;
    armmer_count = 0;
    start = 0;
    end = n-1;
    while(start < end) {
        int test = materials[start] + materials[end];
        if (test == m) {
            armmer_count++;
            start++;
            end--;
        } else if (test > m) {
            end--;
        } else {
            start++;
        }
    }
    cout << armmer_count << endl;
}