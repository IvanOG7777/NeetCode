//
// Created by elder on 2/11/2026.
//


#include <iostream>
#include <vector>
#include <map>
#include <array>

class Solution {
    private:
    std:: map <std::array<int,26>, std:: vector <std:: string>> map;
    std:: vector <std:: vector<std:: string>> groupedAnagrams;
public:
    std:: vector<std:: vector<std:: string>> groupAnagrams(std:: vector<std:: string>& strs) {

        for (size_t i = 0; i < strs.size(); ++i) { // words
            std::array<int,26> array{}; // create fresh array per word
            for (size_t c = 0; c < strs[i].size(); c++) { // chars in word
                array[strs[i][c] - 'a']++;
            }
            map[array].push_back(strs[i]);
        }

        for (auto &pair : map) {
            groupedAnagrams.push_back(pair.second);
        }

        return groupedAnagrams;
    }
};


int main() {
    Solution sol;
    std:: vector<std:: vector<std::string>> groupedAnagrams;
    std:: vector <std:: string> strings = {"act","pots","tops","cat","stop","hat"};
    std:: map <std::array<int,26>, std:: vector <std:: string>> map;

    groupedAnagrams = sol.groupAnagrams(strings);

    for (auto &vector : groupedAnagrams) {
        for (auto &s : vector) {
            std:: cout << s << " ";
        }
        std:: cout << std::endl;
    }


    return 0;
}