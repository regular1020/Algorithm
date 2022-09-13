#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int total_sold;
    cin >> total_sold;
    map<string, int> sold_count;
    string book;
    for (int i = 0; i < total_sold; i++) {
        cin >> book;
        auto item = sold_count.find(book);
        if (item == sold_count.end()) {
            sold_count.insert(pair<string, int>(book, 1));
        } else {
            sold_count[book] = sold_count[book]+1;
        }
    }
    map<string, int>::iterator p = sold_count.begin();
    int max_count = 0;
    string best_selling_book;
    while (p != sold_count.end())
    {
        if (p->second > max_count) {
            max_count = p->second;
            best_selling_book = p->first;
        }
        p++;
    }
    cout << best_selling_book << endl;
}