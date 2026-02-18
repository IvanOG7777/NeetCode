//
// Created by elder on 2/16/2026.
//

#include <iostream>

class Solution {
public:
    bool isPalindrome(std:: string &s) {
        int left  = 0;
        int right = s.size() - 1;
        bool b_isPalindrome = true;

        if (s.empty()) {
            b_isPalindrome = true;
            return b_isPalindrome;
        }

        if (s.length() == 1) {
            b_isPalindrome = true;
            return b_isPalindrome;
        }

        while (left <= right) {
            char leftChar = s[left];
            char rightChar = s[right];


            if (!isalnum(leftChar)) {
                left++;
                continue;
            }

            if (!isalnum(rightChar)) {
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
        }
        return b_isPalindrome;
    }
};

int main() {
    Solution sol;
    std:: string s1 = "mom";
    std:: string s2 = "0P";
    std:: string s3 = "racecar";
    std:: string s4 ="0Was it a car or a cat I saw0?";
    std:: string s5 = "tab a cat";
    std:: string s6 = "a.";
    std:: string s7 = ".,";
    std:: string s8 = "A Santa at NASA";
    std:: string s9 = "0P";

    bool b_isPalindrome = sol.isPalindrome(s4);



    std:: cout << "Is palindrome: " << b_isPalindrome << std::endl;

    return 0;
}