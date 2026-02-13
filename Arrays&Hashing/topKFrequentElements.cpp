//
// Created by elder on 2/11/2026.
//

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std:: vector<int> topKFrequent(std:: vector<int>& nums, int k) {

    }
};


int main() {

    std:: vector<int> nums = {1,2,2,3,3,3};
    int k = 2; // return the 2 most frequent numbers, in this case it would be 2 and 3
    std:: map<int,int> map;

    for (auto &num : nums) {
        map[num]++;
    }

    // map
    //
    // val: 1, count 1
    // val: 2, count 2
    // val: 3, count 3
}