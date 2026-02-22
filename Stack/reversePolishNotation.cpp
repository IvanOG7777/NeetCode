//
// Created by elder on 2/21/2026.
//

#include <iostream>
#include <vector>
#include <stack>

class Solution {
    int result = 0;
    int a = 0;
    int b = 0;

    std:: stack<std::string> operandStack;
public:
    int evalRPN(std::vector<std::string> &tokens) {
        if (tokens.empty()) return 0;

        if (tokens.size() == 1) return stoi(tokens[0]);
        for (auto &token: tokens) {
            int currentSum = 0;

            if (token.size() >= 2) {
                if (token[0] == '+') {
                    operandStack.push(token.substr(1));
                    continue;
                } else if (token[0] == '-') {
                    operandStack.push(token);
                    continue;
                }
            }

            switch (token[0]) {
                case '+':
                    b = stoi(operandStack.top());
                    operandStack.pop();
                    a = stoi(operandStack.top());
                    operandStack.pop();

                    currentSum = a + b;
                    operandStack.push(std::to_string(currentSum));
                    result = currentSum;
                    continue;
                case '-':
                    b = stoi(operandStack.top());
                    operandStack.pop();
                    a = stoi(operandStack.top());
                    operandStack.pop();

                    currentSum = a - b;
                    operandStack.push(std::to_string(currentSum));
                    result = currentSum;
                    continue;
                case '*':
                    b = stoi(operandStack.top());
                    operandStack.pop();
                    a = stoi(operandStack.top());
                    operandStack.pop();

                    currentSum = a * b;
                    operandStack.push(std::to_string(currentSum));
                    result = currentSum;
                    continue;
                case '/':
                    b = stoi(operandStack.top());
                    operandStack.pop();
                    a = stoi(operandStack.top());
                    operandStack.pop();

                    currentSum = a / b;
                    operandStack.push(std::to_string(currentSum));
                    result = currentSum;
                    continue;
                default:
                    break;
            }
            operandStack.push(token);
        }
        return result;
    }
};


int main() {

    Solution solution;
    // std::vector<std::string> tokens = {"1", "2", "+", "3", "*", "4", "-"};
    // std::vector<std::string> tokens2 = {"2","1","+","3","*"};
    std:: vector<std::string> tokens3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    int result = solution.evalRPN(tokens3);

    std:: cout << result << std::endl;

    return 0;
}
