#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int meeting_count;
    vector<pair<int, int>> meetings;
    cin >> meeting_count;
    for (int i = 0; i < meeting_count; i++) {
        int start_time, end_time;
        cin >> start_time >> end_time;
        meetings.push_back(make_pair(start_time, end_time));
    }
    sort(meetings.begin(), meetings.end(), compare);
    int finish_time = 0;
    int available_meeting = 0;
    for (int i = 0; i < meeting_count; i++) {
        if (finish_time <= meetings[i].first) {
            finish_time = meetings[i].second;
            available_meeting++;
        }
    }
    cout << available_meeting << endl;
}