//
// Created by elder on 2/22/2026.
//

#include <iostream>
#include <stack>
#include <vector>

class Solution {
private:
    int currentLargest = 0;
    std:: stack<int> tempStack;
public:
    std:: vector<int> dailyTemperatures(std:: vector<int>& temperatures) {
        std:: vector<int> temps(temperatures.size(), 0);

        for (int i = static_cast<int>(temperatures.size() - 1); i >= 0; i--) {
            while (!tempStack.empty() && temperatures[i] >= temperatures[tempStack.top()]) {
                tempStack.pop();
            }

            if (!tempStack.empty()) {
                currentLargest = tempStack.top();
            }

            if (tempStack.empty()) {
                temps[i] = 0;
            } else {
                temps[i] = currentLargest - i;
            }

            tempStack.push(i);
        }
        return temps;
    }
};


int main () {

    std:: vector<int> temperatures = {30,38,30,36,35,40,28};
    std:: vector<int> temps(temperatures.size(), 0);
    int currentLargest = 0;

    std:: stack<int> tempStack;
    for (int i = static_cast<int>(temperatures.size() - 1); i >= 0; i--) {
        while (!tempStack.empty() && temperatures[i] >= temperatures[tempStack.top()]) {
            tempStack.pop();
        }

        if (!tempStack.empty()) {
            currentLargest = tempStack.top();
        }

        if (tempStack.empty()) {
            temps[i] = 0;
        } else {
            temps[i] = currentLargest - i;
        }

        tempStack.push(i);
    }

    for (auto &num : temps) {
        std:: cout << num << " ";
    }

    return 0;
}
