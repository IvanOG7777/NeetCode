//
// Created by elder on 2/16/2026.
//

#include <iostream>

class Solution {
public:
    bool isPalindrome(std:: string &s) {
        size_t left  = 0;
        size_t right = s.size() - 1;
        bool b_isPalindrome = false;

        if (s.empty()) {
            b_isPalindrome = true;
            return b_isPalindrome;
        }

        if (s.length() == 1) {
            b_isPalindrome = true;
            return b_isPalindrome;
        }

        while (left < s.size()/2 && right > s.size()/2) {
            char leftChar = s[left];
            char rightChar = s[right];

            if (left == right  && leftChar == rightChar) {
                return false;
            }


            if (!isalpha(leftChar)) {
                left++;
                continue;
            }

            if (!isalpha(rightChar)) {
                right--;
                continue;
            }

            leftChar = tolower(leftChar);
            rightChar = tolower(rightChar);

            if (leftChar == rightChar) {
                b_isPalindrome = true;
                left++;
                right--;
            } else {
                b_isPalindrome = false;
                break;
            }

            if (left == right) return false;
        }
        return b_isPalindrome;
    }
};


int main() {

    Solution sol;
    std:: string s="mom";
    bool b_isPalindrome = sol.isPalindrome(s);


    std:: cout << "Is string palindrome: " << (b_isPalindrome ? "True" : "False") << std:: endl;

    return 0;
}