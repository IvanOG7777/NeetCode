//
// Created by elder on 2/14/2026.
//

#include <iostream>
#include <vector>

class Solution {
public:

    std:: string encode(std:: vector<std:: string>& strs) {
        if (strs.empty()) return "";
        std:: string outString = "";
        for (auto &str : strs) {
            if (str == "") {
                size_t currentLength  = 1;
                std:: string joinedString = (std::to_string(currentLength) + "#") + str;
                outString += joinedString;
                break;
            }
            size_t currentLength = str.length();
            std:: string joinedString = (std::to_string(currentLength) + "#") + str;
            outString += joinedString;
        }

        return outString;
    }

    std:: vector<std:: string> decode(std:: string s) {
        std:: vector<std::string> decodedStrings;
        bool seenFirstPound = false;
        for (size_t i = 0; i < s.length(); i++) {
            seenFirstPound = false;

            if (s[i] == '#') seenFirstPound = true;

            if (seenFirstPound) {
                size_t substringLength = s[i - 1] - '0';
                std:: string substring = s.substr(i + 1, substringLength);
                decodedStrings.push_back(substring);
                i += substringLength;
            }
        }

        return decodedStrings;
    }
};

int main () {
    Solution solution;
    std:: vector<std:: string> strs = {""};
    std:: string encodedString = solution.encode(strs);
    std:: vector<std::string> decodedStrings = solution.decode(encodedString);

    std:: cout << encodedString << std::endl;
    std:: cout << std:: endl;

    for (auto &str : decodedStrings) {
        std:: cout << str << std::endl;
    }


}