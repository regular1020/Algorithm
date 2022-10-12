#include <iostream>

using namespace std;

int main() {
    int user_count, friend_connection_count;
    cin >> user_count >> friend_connection_count;
    int** kevin_bacon = new int* [user_count+1];
    for (int i = 0; i <= user_count; i++) {
        kevin_bacon[i] = new int [user_count+1];
    }
    for (int i = 0; i <= user_count; i++) {
        for (int j = 0; j <= user_count; j++) {
            kevin_bacon[i][j] = 99999;
        }
        kevin_bacon[i][i] = 0;
    }
    for (int i = 0; i < friend_connection_count; i++) {
        int a, b;
        cin >> a >> b;
        kevin_bacon[a][b] = 1;
        kevin_bacon[b][a] = 1;
    }
    for (int k = 1; k <= user_count; k++) {
        for (int i = 1; i <= user_count; i++) {
            for (int j = 1; j <= user_count; j++) {
                if (kevin_bacon[i][k] + kevin_bacon[k][j] < kevin_bacon[i][j]) {
                    kevin_bacon[i][j] = kevin_bacon[i][k] + kevin_bacon[k][j];
                }
            }
        }
    }
    int min_kevin_user = 0;
    int min_kevin = 99999;
    for (int i = 1; i <= user_count; i++) {
        int i_kevin = 0;
        for (int j = 1; j <= user_count; j++) {
            i_kevin = i_kevin + kevin_bacon[i][j];
        }
        if (i_kevin < min_kevin) {
            min_kevin_user = i;
            min_kevin = i_kevin;
        }
    }
    cout << min_kevin_user << endl;
}