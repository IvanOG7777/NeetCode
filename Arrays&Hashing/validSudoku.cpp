//
// Created by Ivan on 2/15/2026.
//

#include <iostream>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std:: vector<std:: vector<char>>& board) {

    }
};


int main() {

    std:: vector<std:: vector<char>> board = {
        {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '2', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    for (auto &row : board) {
        for (auto &val : row) {
            std:: cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}