//
// Created by elder on 2/16/2026.
//

#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
    public:
    int longestConsecutive(std::vector<int>& nums) {
        int longest = 0;
        std::unordered_set<int> set;
        for (auto &num : nums) {
            set.insert(num);
        }

        for (auto &val : set) {
            if (set.find(val - 1) == set.end()) {
                int length = 0;
                int num = val;
                while (set.find(num) != set.end()) {
                    length++;
                    num++;
                }

                longest = std:: max(longest, length);
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
    std:: vector<int> nums {2,10,3,5,3,4,4,20};

    int res = s.longestConsecutive(nums);

    std:: cout << res << std::endl;

    return 0;

    std:: unordered_set<int> subsequence;
    int result;
    std:: vector<int> resultHelperVector;

    result = s.longestConsecutive(nums);

    std:: cout << result << std::endl;

    return 0;
}