#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    cin >> line;
    int last = 0;
    vector<int> numbers;
    vector<char> symbols;
    for (int i = 1; i < line.size(); i++) {
        if (line[i] == '+'){
            numbers.push_back(stoi(line.substr(last, i-last)));
            symbols.push_back('+');
            last = i+1;
        }
        else if (line[i] == '-') {
            numbers.push_back(stoi(line.substr(last, i-last)));
            symbols.push_back('-');
            last = i+1;
        }
    }
    numbers.push_back(stoi(line.substr(last)));
    int number_index = 0;
    for (int i = 0; i < symbols.size(); i++) {
        if (symbols[i] == '+') {
            int num1, num2;
            num1 = numbers[number_index];
            num2 = numbers[number_index+1];
            numbers.erase(numbers.begin()+number_index);
            numbers.erase(numbers.begin()+number_index);
            numbers.insert(numbers.begin()+number_index, num1+num2);
        }
        else {
            number_index++;
        }
    }
    int total = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        total = total-numbers[i];
    }
    cout << total << endl;
}