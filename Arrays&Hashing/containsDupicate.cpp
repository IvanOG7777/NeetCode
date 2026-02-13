//
// Created by elder on 2/10/2026.
//

#include <iostream>
#include <map>
#include <vector>

class Solution {
private:
    std:: map<int, int> vectorMap;
    public:
    bool hasDuplicate(std:: vector<int>& nums) {
        for (auto &num : nums) {
            vectorMap[num]++;
            if (vectorMap[num] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main () {

    Solution s;

    std:: map<int, int> vectorMap;

    std:: vector <int> nums = {1,2,3};
    bool duplicate = s.hasDuplicate(nums);

    // for (auto &num : nums) {
    //     vectorMap[num]++;
    //     if (vectorMap[num] > 1) {
    //         duplicate = true;
    //         break;
    //     }
    // }

    std:: cout << "Contains duplicate: " << (duplicate ? "True" : "False") << "\n";

    return 0;
}