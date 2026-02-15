//
// Created by elder on 2/15/2026.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std:: vector<int> productExceptSelf(std:: vector<int>& nums) {
        size_t n = nums.size();
        std:: vector<int> prefixNums(n);
        std:: vector<int> postfixNums(n);
        std:: vector<int> output(n);

        prefixNums[0] = nums[0];
        postfixNums[n - 1] = nums[n - 1];

        for (size_t i = 1; i < n; i++) {
            prefixNums[i] = nums[i] * prefixNums[i - 1];
        }
        for (size_t i = n - 1; i > 0; i--) {
            postfixNums[i - 1] = nums[i - 1] * postfixNums[i];
        }

        for (size_t i = 0; i < n; i++) {
            if (i - 1 == -1) {
                output[i] = 1 * postfixNums[i];
                continue;
            }

            if (i >= n - 1) {
                output[i] = prefixNums[i - 1];
                continue;
            }

            output[i] = prefixNums[i-1] * postfixNums[i + 1];
        }

        return output;
    }
};


int main() {
    std:: vector<int> nums = {4,3,2,1,2};
    Solution s;
    size_t n = nums.size();
    std:: vector<int> prefixNums(n);
    std:: vector<int> postfixNums(n);
    std:: vector<int> output(n);

    output = s.productExceptSelf(nums);
    for (auto &num : output) {
        std:: cout << num << " ";
    }
}
