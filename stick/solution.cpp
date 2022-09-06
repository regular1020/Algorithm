#include <iostream>
using namespace std;

int main() {
    int stick = 64;
    int want;
    cin >> want;
    int sticks[64];
    int index = 0;
    sticks[index] = stick;
    while (stick != want)
    {
        int min = sticks[index]/2;
        if (stick - min >= want) {
            sticks[index] = min;
            stick = stick - min;
        }
        else {
            sticks[index] = min;
            index++;
            sticks[index] = min;
        }
    }
    index++;
    cout << index << endl;
}