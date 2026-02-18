//
// Created by Ivan on 2/17/2026.
//

#include <iostream>
#include <vector>

class Solution {
private:
    std:: vector<int> result;
public:
    std:: vector<int> twoSum(std::  vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int leftNum = numbers[left];
            int rightNum = numbers[right];

            int sum = leftNum + rightNum;

            if (sum < target) {
                left++;
                continue;
            }

            if (sum > target) {
                right--;
                continue;
            }

            if (sum == target) {
                result.push_back(left+1);
                result.push_back(right+1);
                left++;
                right--;
                break;
            }
            left++;
            right--;
        }
        return result;
    }
};


int main() {
    Solution solution;
    std::  vector<int> numbers1 = {1,2,3,4};
    std::vector<int> numbers2 = {0,-1};
    int target1 = 3;
    int target2 = -1;
    int target3 = 3;
    std:: vector<int> result = solution.twoSum(numbers2, target2);

    if (result.empty()) {
        std:: cout << "No values summed to target" << std:: endl;
        return 0;
    }

    for (auto &num  : result) {
        std:: cout << num << ", ";
    }
}
