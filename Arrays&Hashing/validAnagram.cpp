//
// Created by elder on 2/10/2026.
//

#include <iostream>
#include <map>

class Solution {
    std:: map<char, int> stringMap1;
    std:: map<char, int> stringMap2;
public:
    bool isAnagram(std:: string &s, std:: string &t) {
        if (s.length() != t.length()) return false;

        for (auto &val : s) {
            stringMap1[val]++;
        }

        for (auto &val : t) {
            stringMap2[val]++;
        }

        for (size_t i = 0; i < stringMap1.size(); i++) {
            if (stringMap1[i] != stringMap2[i]) return false;
        }
        return true;
    }
};


int main() {
    Solution s;
    std:: map<char, int> stringMap;
    std:: string s1 = "bx";
    std:: string s2 = "bx";
    bool isAnagram = s.isAnagram(s1, s2);


    std:: cout << "Are strings anagrams: " << (isAnagram ? "True" : "False") << std:: endl;

    return 0;

}