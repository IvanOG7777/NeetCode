//
// Created by elder on 2/14/2026.
//

#include <iostream>
#include <vector>
class Solution {
public:

    std:: string encode(std:: vector<std:: string>& strs) {

    }

    std:: vector<std:: string> decode(std:: string s) {

    }
};

int main () {
    std:: vector<std:: string> strings = {"Hello", "world"};
    std:: string outString;
    size_t totalLength = 0;

    for (auto &string : strings) {
        size_t currentLength = string.length();
        std:: cout << currentLength << std::endl;
        totalLength += currentLength;
        outString += string;
    }

    std:: cout << outString << std::endl;
    std:: cout << totalLength << std::endl;

}

//get the size of the string
// pass in the length + "string" to the out string

// when decoding look for first number, remember it
// while firstNumber seen
// count the character after that until length
// unsee the first one