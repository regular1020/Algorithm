#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {
	int word_count; 
    cin >> word_count;
	vector<string> word_vector;

	for (int word_index = 0; word_index < word_count; word_index++) {
		string new_string; 
        cin >> new_string;
		if (word_vector.size() == 0) {
			word_vector.push_back(new_string);
		}
		else {
			queue<char> word_queue;

			for (int k = 0; k < new_string.size(); k++) {
				word_queue.push(new_string[k]);
			}

			bool is_new = true;

			for (int j = 0; j < word_vector.size(); j++) {
				for (int k = 0; k < new_string.size(); k++) {
                    string compstr = "";
                    for (int i = 0; i < word_queue.size(); i++) {
                        compstr += word_queue.front();
                        word_queue.push(word_queue.front());
                        word_queue.pop();
                    }

					if (compstr == word_vector[j]) {
						is_new = false;
						break;
					}
					
					word_queue.push(word_queue.front());
					word_queue.pop();
				}

				if (!is_new) {
					break;
				}
			}

			if (is_new) {
				word_vector.push_back(new_string);
			}
		}
	}

	cout << word_vector.size() << "\n";

	return 0;
}