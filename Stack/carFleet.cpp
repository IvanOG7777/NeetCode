//
// Created by elder on 2/22/2026.
//

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
    std:: vector<std::pair<int,int>> positionANDSpeed;
    std:: stack<float> stack;
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        positionANDSpeed.reserve(position.size());
        for (size_t i = 0; i < position.size(); i++) {
            positionANDSpeed.emplace_back(position[i], speed[i]);
        }

        for (int i = static_cast<int>(positionANDSpeed.size() - 1); i>= 0; i--) {
            float currentDistance = static_cast<float>(target - positionANDSpeed[i].first) / static_cast<float>(positionANDSpeed[i].second);

            if (stack.empty()) {
                stack.push(currentDistance);
            } else if (currentDistance > stack.top()) {
                stack.push(currentDistance);
            }
        }

        return static_cast<int>(stack.size());
    }
};


int main() {

    Solution
    int target = 10;
    std:: vector<int> position = {3,5,7};
    std:: vector<int> speed = {3,2,1};
    std::stack<float> stack;

    std::vector<std::pair<int,int>> positions_speed;
    positions_speed.reserve(position.size());
    for (int i = 0; i < position.size(); i++) {
        positions_speed.emplace_back(position[i],speed[i]);
    }

    std::sort(positions_speed.begin(), positions_speed.end());

    for (auto &pair : positions_speed) {
        std:: cout << "Position: " << pair.first << " Speed: " << pair.second << std::endl;
    }


    for (int i = static_cast<int>(positions_speed.size() - 1); i >= 0; i--) {
        float currentDistance = static_cast<float>(target - positions_speed[i].first) / static_cast<float>(positions_speed[i].second);

        if (stack.empty()) {
            stack.push(currentDistance);
        } else if (currentDistance > stack.top()) {
            stack.push(currentDistance);
        }
    }

    std:: cout << stack.size() << std:: endl;


    return 0;
}