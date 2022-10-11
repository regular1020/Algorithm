#include <iostream>

#define INT_MAX 99999999

using namespace std;

int main() {
    int peopleCount, person1, person2, relationshipCount;
    cin >> peopleCount;
    cin >> person1 >> person2;
    cin >> relationshipCount;
    int** relationMap = new int* [peopleCount+1];
    for (int i = 1; i <= peopleCount; i++) {
        relationMap[i] = new int [peopleCount+1];
    }
    for (int i = 1; i <= peopleCount; i++) {
        for (int j = 1; j <= peopleCount; j++) {
            relationMap[i][j] = INT_MAX;
        }
    }
    for (int c = 0; c < relationshipCount; c++) {
        int parent, child;
        cin >> parent >> child;
        relationMap[parent][child] = 1;
        relationMap[child][parent] = 1;
    }

    int* relations = new int [peopleCount+1];
    bool* visited = new bool [peopleCount+1] {false};
    
    for (int i = 1; i <= peopleCount; i++) {
        relations[i] = relationMap[person1][i];
    }
    visited[person1] = true;
    relations[person1] = 0;

    for (int i = 0; i < peopleCount-1; i++) {
        int selected, min_selected;
        min_selected = INT32_MAX;
        for (int j = 1; j <= peopleCount; j++) {
            if (visited[j] == true) {
                continue;
            }
            if (relations[j] < min_selected) {
                selected = j;
                min_selected = relations[j];
            }
        }

        visited[selected] = true;
        for (int k = 1; k <= peopleCount; k++) {
            if (visited[k]) {
                continue;
            }
            if (relations[k] > relations[selected] + relationMap[selected][k]) {
                relations[k] = relations[selected] + relationMap[selected][k];
            }
        }
    }

    if (relations[person2] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << relations[person2] << endl;
    }
}