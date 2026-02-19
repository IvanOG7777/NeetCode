//
// Created by Ivan on 2/18/2026.
//


#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int left = i;
            int right = heights.size() - 1;

            while (left < right) {

                int width = right - left;
                int height = std::min(heights[left],heights[right]);
                int currentArea = height * width;

                if (currentArea > maxArea) {
                    maxArea = currentArea;
                }

                if (heights[left] < heights[right]) {
                    left++;
                    continue;
                }

                if (heights[right] < heights[left]) {
                    right--;
                    continue;
                }

                left++;
                right--;
            }
        }
        return maxArea;
    }
};


int main() {

    Solution solution;
    std:: vector<int> nums = {1,7,2,5,4,7,3,6};
    std:: vector<int> nums2 = {1,7,2,5,12,3,500,500,7,8,4,7,3,6};
    std:: vector<int> nums3 = {1,8,100,2,100,4,8,3,7};
    int maxArea = solution.maxArea(nums3);


    std:: cout << "The max area is: " <<  maxArea << std::endl;
}