//
// Created by elder on 2/11/2026.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

class Solution {
private:
    std:: priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> queue;
    std:: map<int,int> map;
    std:: vector<int> returnedNums;
public:
    std:: vector<int> topKFrequent(std:: vector<int>& nums, int k) {
        for (auto &num : nums) {
            map[num]++;
        }

        for (auto &pair : map) {
            std::pair<int,int> newPair = {pair.second, pair.first};
            queue.emplace(newPair);

            if (queue.size() > k) {
                queue.pop();
            }
        }

        while (!queue.empty()) {
            returnedNums.emplace_back(queue.top().second);
            queue.pop();
        }

        return returnedNums;
    }
};


int main() {

    std:: vector<int> nums = {1,1,1,2,2,3,3};
    int k = 2; // return the 2 most frequent numbers, in this case it would be 2 and 3
    std:: map<int,int> map;
    std:: priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> queue;
    std:: vector<int> newNums;

    for (auto &num : nums) {
        map[num]++;
    }

    for (auto &pair : map) {
        std::pair<int,int> newPair = {pair.second, pair.first};
        queue.emplace(newPair);
        newNums.push_back(newPair.second);

        if (queue.size() > k) {
            queue.pop();
            newNums.erase(newNums.begin());
        }
    }

    std:: cout << std:: endl;
    for (auto &num : newNums) {
        std:: cout << num << " ";
    }

    // std:: cout << std:: endl;
    // while (!queue.empty()) {
    //     std:: cout << queue.top().first << " " << queue.top().second << std::endl;
    //     queue.pop();
    // }

}