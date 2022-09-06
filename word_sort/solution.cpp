#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int word_count;
    cin >> word_count;
    string* words = new string[word_count];
    for (int i = 0; i < word_count; i++) {
        cin >> words[i];
    }
    int len = 1;
    sort(words, words+word_count);
    string* words2 = new string[word_count];
    int words2_index = 0;
    for (int i = 0; i < word_count-1; i++) {
        if (words[i].compare(words[i+1]) != 0) {
            words2[words2_index] = words[i];
            words2_index++;
        }
    }
    words2[words2_index] = words[word_count-1];
    words2_index++;
    words=words2;
    word_count = words2_index;
    while (word_count != 0) {
        sort(words, words+word_count);
        string* left_list = new string[word_count];
        int left_index = 0;
        int tmp = word_count;
        for (int i = 0; i < word_count; i++) {
            if (words[i].length() == len) {
                cout << words[i] << endl;
                tmp--;
            } else {
                left_list[left_index] = words[i];
                left_index++;
            }
        }
        word_count = tmp;
        len++;
        words = left_list;
    }
}