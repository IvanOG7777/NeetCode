//
// Created by elder on 2/10/2026.
//

#include <iostream>
#include <vector>

class Solution {
private:
    std:: vector <int> validIndices;
public:
    std:: vector<int> twoSum(std:: vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    validIndices.push_back(i);
                    validIndices.push_back(j);
                    return validIndices;
                }
            }
        }
    }
};


int main() {

    Solution s;
    std:: vector<int> nums = {2,5,5,11};
    std:: vector<int>validIndices;
    int target = 10;

    validIndices = s.twoSum(nums, target);

    for (auto &num : validIndices) {
        std:: cout << num << " ";
    }

    return 0;
}