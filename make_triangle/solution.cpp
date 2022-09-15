#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int straw_count;
    cin >> straw_count;
    int* straws = new int[straw_count];
    for (int i = 0; i < straw_count; i++) {
        cin >> straws[i];
    }
    sort(straws, straws+straw_count);
    int first, middle, last, result;
    last = straw_count-1;
    middle = straw_count-2;
    first = straw_count-3;
    result = -1;
    while(true){
        if (straws[last] < straws[middle] + straws[first]) {
            result = straws[last] + straws[middle] + straws[first];
            break;
        } else {
            last--;
            middle--;
            first--;
            result = -1;
        }
        if (first == -1) {
            break;
        }
    }
    cout << result << endl;
}