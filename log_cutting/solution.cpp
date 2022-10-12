#include <iostream>

using namespace std;

int main() {
    long long int tree_count, log_length;
    cin >> tree_count >> log_length;
    long long int* trees = new long long int[tree_count];
    for (int i = 0; i < tree_count; i++) {
        cin >> trees[i];
    }
    long long int low, high, middle, answer;
    low = 0;
    high = 1000000000;
    answer = 0;
    while (high >= low) {
        long long int log_sum = 0;
        middle = (high+low)/2;
        for (int i = 0; i < tree_count; i++) {
            if (trees[i] > middle) {
                log_sum = log_sum + (trees[i] - middle);
            }
        }
        if (log_sum == log_length) {
            answer = middle;
            break;
        }
        else if (log_sum > log_length) {
            if (answer < middle) {
                answer = middle;
            }
            low = middle+1;
        } else if (log_sum < log_length){
            high = middle-1;
        }
    }
    cout << answer;
}