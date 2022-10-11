#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    for (int c = 0; c < testCase; c++) {
        int length;
        cin >> length;
        string * math_expression = new string[length];
        for (int i = 0; i < length; i++) {
            cin >> math_expression[i];
        }
        stack<string> postfix_stack;
        vector<string> postfix_expression;
        for (int i = 0; i < length; i++) {
            if (math_expression[i] == "(") {
                postfix_stack.push(math_expression[i]);
            }
            else if (math_expression[i] == "*") {
                postfix_stack.push(math_expression[i]);
            }
            else if (math_expression[i] == "+" || math_expression[i] == "-") {
                while(!postfix_stack.empty()) {
                    string tmp = postfix_stack.top();
                    if (tmp == "(") {
                        break;
                    }
                    postfix_stack.pop();
                    postfix_expression.push_back(tmp);
                }
                postfix_stack.push(math_expression[i]);
            } else if (math_expression[i] == ")") {
                while (postfix_stack.top() != "(") {
                    string tmp = postfix_stack.top();
                    postfix_stack.pop();
                    postfix_expression.push_back(tmp);
                }
                postfix_stack.pop();
            } else {
                postfix_expression.push_back(math_expression[i]);
            }
        }
        while (!postfix_stack.empty()) {
            string tmp = postfix_stack.top();
            postfix_stack.pop();
            postfix_expression.push_back(tmp);
        }
        stack<string> calculate_stack;
        for (int i = 0; i < postfix_expression.size(); i++) {
            string tmp = postfix_expression[i];
            if (tmp == "+") {
                int tmp_number2 = stoi(calculate_stack.top());
                calculate_stack.pop();
                int tmp_number1 = stoi(calculate_stack.top());
                calculate_stack.pop();
                calculate_stack.push(to_string(tmp_number1+tmp_number2));
            }
            else if (tmp == "-") {
                int tmp_number2 = stoi(calculate_stack.top());
                calculate_stack.pop();
                int tmp_number1 = stoi(calculate_stack.top());
                calculate_stack.pop();
                calculate_stack.push(to_string(tmp_number1-tmp_number2));
            }
            else if (tmp == "*") {
                int tmp_number2 = stoi(calculate_stack.top());
                calculate_stack.pop();
                int tmp_number1 = stoi(calculate_stack.top());
                calculate_stack.pop();
                calculate_stack.push(to_string(tmp_number1*tmp_number2));
            }
            else {
                calculate_stack.push(tmp);
            }
        }
        cout << calculate_stack.top() << endl;
    }
}