#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string in_string;
    cin >> in_string;
    string compare_string[2];
    compare_string[0] = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for (int i = 1; i < in_string.length()-1; i++) {
        for (int j = i; j < in_string.length()-1; j++) {
            string str1 = in_string.substr(0, i);
            reverse(str1.begin(), str1.end());
            string str2 = in_string.substr(i,j-i+1);
            reverse(str2.begin(), str2.end());
            string str3 = in_string.substr(j+1,51);
            reverse(str3.begin(), str3.end());
            compare_string[1] = str1+str2+str3;
            sort(compare_string, compare_string+2);
        }
    }
    cout << compare_string[0] << endl;
}