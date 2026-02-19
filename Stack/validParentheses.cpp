//
// Created by elder on 2/18/2026.
//

#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std:: string &s) {
        if (s.empty()) return false;
        if (s.size() == 1) return false;
        std:: stack<char> bracketStack;
        if (s.size() == 1) return false;
        for (auto &bracket : s) {
            if (bracket == '(' || bracket == '{' || bracket == '[') {
                std:: cout <<"Pushed: " <<  bracket <<  " into the stack" << std::endl;
                bracketStack.push(bracket);
                continue;
            }
            std:: cout << "Bracket: " << bracket << std::endl;

            if (!bracketStack.empty()) {
                if (bracketStack.top() == '(' && bracket == ')') {
                    std:: cout << "Found pair"<< std:: endl;
                    bracketStack.pop();
                    continue;
                }

                if (bracketStack.top() == '{' && bracket == '}') {
                    std:: cout << "Found pair"<< std:: endl;
                    bracketStack.pop();
                    continue;
                }

                if (bracketStack.top() == '[' && bracket == ']') {
                    std:: cout << "Found pair"<< std:: endl;
                    bracketStack.pop();
                    continue;
                }
            }
            return false;
        }

        if (!bracketStack.empty()) return false;
        return true;
    }
};

int main() {
    Solution s;
    std::string brackets = "}";
    std::stack<char> bracketStack;
    bool isPair = s.isValid(brackets);


    std::cout << "Valid: " << (isPair ? "true" : "false") << std::endl;


    return 0;
}
