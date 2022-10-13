#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int visit[100001] = {0, };
    visit[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == k) {
            cout << visit[current]-1 << endl;
            break;
        }

        if (current+1 < 100001 && current+1 >= 0) {
            if (visit[current+1] == 0) {
                visit[current+1] = visit[current]+1;
                q.push(current+1);
            }
        }
        if (current-1 < 100001 && current-1 >= 0) {
            if (visit[current-1] == 0) {
                visit[current-1] = visit[current]+1;
                q.push(current-1);
            }
        }
        if (current*2 < 100001 && current*2 >= 0) {
            if (visit[current*2] == 0) {
                visit[current*2] = visit[current]+1;
                q.push(current*2);
            }
        }
    }
}