//
// Created by elder on 2/15/2026.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std:: vector<int> productExceptSelf(std:: vector<int>& nums) {

    }
};


int main() {
    std:: vector<int> nums = {1,2,3,4};
    size_t n = nums.size();
    std:: vector<int> prefixNums(n);
    std:: vector<int> postfixNums(n);

    prefixNums[0] = nums[0];
    postfixNums[n - 1] = nums[n - 1];

    for (size_t i = 1; i < n; i++) {
        prefixNums[i] = nums[i] * prefixNums[i - 1];
    }

    for (int i = n - 1; i > 0; i--) {
        postfixNums[i] = postfixNums[i] * nums[i - 1];
    }

    for (auto &num : prefixNums) {
        std:: cout << num << " ";
    }

    std:: cout << std::endl;

    for (auto &num : postfixNums) {
        std:: cout << num << " ";
    }

}
