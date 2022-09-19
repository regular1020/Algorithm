#include <iostream>

using namespace std;

int main() {
    int testCese;
    cin >> testCese;
    for (int c = 0; c < testCese; c++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int marin_count;
        int radius_minus, radius_plus, dist;
        radius_minus = (r1-r2) * (r1-r2);
        radius_plus = (r1+r2) * (r1+r2);
        dist = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        if (radius_minus < dist && dist < radius_plus) {
            marin_count = 2;
        } 
        else if (x1 == x2 && y1 == y2 && r1 == r2) {
            marin_count = -1;
        } 
        else if (radius_plus == dist || radius_minus == dist) {
            marin_count = 1;
        } else {
            marin_count = 0;
        }
        cout << marin_count << endl;
    }
}