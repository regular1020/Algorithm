#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    int tc;
    cin >> tc;
    for (int c = 0; c < tc; c++) {
        int applicant_count;
        cin >> applicant_count;
        vector<pair<int, int>> applicants;
        int max_paper = 0;
        int max_interview = 0;
        for (int i = 0; i < applicant_count; i++) {
            int new_paper, new_interview;
            cin >> new_paper >> new_interview;
            applicants.push_back(make_pair(new_paper, new_interview));
        }
        sort(applicants.begin(), applicants.end(), compare);
        int min_interview = applicant_count+1;
        int passed = 0;
        for (int i = 0; i < applicant_count; i++) {
            if (applicants[i].second <= min_interview) {
                passed++;
                min_interview = applicants[i].second;
            }
        }
        cout << passed << endl;
    }
}