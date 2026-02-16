//
// Created by Ivan on 2/15/2026.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
private:
    std:: unordered_set<char> rowSets[9];
    std:: unordered_set<char> colSets[9];
    std:: unordered_set<char> boxes[9];
public:
    bool isValidSudoku(std:: vector<std:: vector<char>>& board) {
        for (size_t row = 0; row < board.size(); row++) {
            for (size_t col = 0; col < board.size(); col++) {
                if (board[row][col] == '.') continue;
                char digit = board[row][col];
                auto boxRow = row / 3;
                auto boxCol = col / 3;
                auto boxId = boxRow * 3 + boxCol;
                if (!rowSets[row].insert(digit).second) {
                    return false;
                }

                if (!colSets[col].insert(digit).second) {
                    return false;
                }

                if (!boxes[boxId].insert(digit).second) {
                    return false;
                }
            }
        }

        return true;
    }
};


int main() {
    Solution s;
    std:: unordered_set<char> rowSets[9];
    std:: unordered_set<char> colSets[9];
    std:: unordered_set<char> boxes[9];

    std:: vector<std:: vector<char>> board = {
        {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    bool valid = s.isValidSudoku(board);

    std:: cout << "Is board valid: " << (valid ? "True" : "Talse") << std:: endl;


    return 0;
}