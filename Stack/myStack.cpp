//
// Created by elder on 2/19/2026.
//


#include <cstdint>
#include <iostream>
#include <stack>

class MinStack {
    int64_t minNum;
    std:: stack<int64_t> stack;

public:
    MinStack() {
        minNum = -1;
    }

    void push(int64_t val) {
        if (stack.empty()) {
            minNum = val;
            stack.push(val);
        } else if (val < minNum) {
            stack.push(2 * val - minNum); // encode the min value
            minNum = val;
        } else {
            stack.push(val);
        }
    }

    void pop() {
        if (stack.empty()) return;

        int64_t currentTop = stack.top();
        stack.pop();

        if (currentTop < minNum) { // if current is less than out min
            minNum = 2 * minNum - currentTop; // change min to the decoded min value
        }
    }

    int64_t top() {
        if (stack.empty()) return -1;

        int64_t currentTop = stack.top();

        return (minNum > currentTop) ? minNum : currentTop;
    }

    int64_t getMin() {
        return minNum;
    }
};


int main() {
    return 0;
}