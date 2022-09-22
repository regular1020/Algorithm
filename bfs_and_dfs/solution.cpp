#include <iostream>
#include <queue>

using namespace std;

int* visited;

void dfs(int** map, int node_count, int start) {
    if (visited[start] == 1) {
        return;
    }
    cout << start << " ";
    visited[start] = 1;
    for (int j = 1; j <= node_count; j++){
        if(map[start][j] == 1) {
            dfs(map, node_count, j);            
        }
    }
}

void bfs(int** map, int node_count, int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int tmp = q.front();
        if (visited[tmp] == 1){
            q.pop();
            continue;
        }
        cout << tmp << " ";
        visited[tmp] = 1;
        for (int i = 1; i <= node_count; i++) {
            if (map[tmp][i] == 1 && visited[i] == 0) {
                q.push(i);
            }
        }
        q.pop();
        // cout << q.size() << endl;
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    visited = new int[n+1] {0};
    int** map = new int* [n+1];
    for (int i = 1; i <= n; i++) {
        map[i] = new int [n+1] {0};
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    dfs(map, n, v);
    cout << endl;

    visited = new int[n+1] {0};

    bfs(map, n, v);
    cout << endl;
}