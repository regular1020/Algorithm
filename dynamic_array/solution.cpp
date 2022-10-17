#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int c = 0; c < tc; c++) {
        int* array_size = new int[101] {0, };
        int* element_count = new int[101] {0, };
        int input_count;
        int copy_count = 0;
        cin >> input_count;
        for (int i = 0; i < input_count; i++) {
            int array_num, data_amount;
            cin >> array_num >> data_amount;
            if (array_size[array_num] < element_count[array_num] + data_amount) {
                int element_log = (int) log2(element_count[array_num] + data_amount);
                element_log++;
                if (element_log == 0) {
                    element_log = 1;
                }
                array_size[array_num] = (int) pow(2, element_log);
                copy_count += element_count[array_num];
            }
            element_count[array_num] += data_amount;
        }
        cout << copy_count << endl;
    }
}