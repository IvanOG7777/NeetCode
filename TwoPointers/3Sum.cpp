//
// Created by Ivan on 2/17/2026.
//

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std:: vector<std:: vector<int>> threeSum(std:: vector<int>& nums) {
        std:: vector<std::vector<int>> results;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    results.push_back({ nums[i],nums[left],nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }

                if (sum < 0) {
                    left++;
                }

                if (sum > 0) {
                    right--;
                }
            }
        }
        return results;
    }
};

int main() {

    Solution solution;
    std:: vector<int> nums = {-1,0,1,2,-1,-4};
                            //-4,-1,-1,0,1,2
    std:: vector<int> nums2 = {-2,0,0,2,2};
    std:: vector<std::vector<int>> results = solution.threeSum(nums);


    for (auto &result : results) {
        for (auto &nums : result) {
            std::cout << nums << " ";
        }
        std::cout << std::endl;
    }

    std:: cout << results.size();

    return 0;
}
