//
// Created by elder on 2/16/2026.
//

#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
private:
    std::unordered_set<int> unorderdSet;
public:
    int longestConsecutive(std:: vector<int>& nums) {
        int longest = 0;
        for (auto &num : nums) {
            if (!unorderdSet.insert(num).second) {

            }
        }

        for (auto &num : nums) {
            if (unorderdSet.find(num - 1) == unorderdSet.end()) {
                int length = 0;
                while (unorderdSet.find(num) != unorderdSet.end()) {
                    length++;
                    num = num + 1;
                }
                longest = std::max(longest, length);
            }
        }

        return longest;
    }
};

// std:: unordered_set<int> subsequence;
// std:: vector<int> result;
// std:: vector<int> consecutiveHelper(std:: unordered_set<int> &sequences, std::vector<int> &nums) {
//     if (sequences.empty()) {
//         return result;
//     }
//     for (auto val : sequences) {
//         if (sequences.find(val - 1) == sequences.end()) {
//             if (sequences.find(val + 1) != sequences.end()) {
//                 result.push_back(val);
//                 sequences.erase(val);
//                 consecutiveHelper(sequences, result);
//             }
//         }
//     }
//
//     return result;
// }


int main() {

    Solution s;
    std:: vector<int> nums {9,1,4,7,3,-1,0,5,8,-1,6};

    std:: unordered_set<int> subsequence;
    int result;
    std:: vector<int> resultHelperVector;

    result = s.longestConsecutive(nums);

    std:: cout << result << std::endl;

    return 0;
}