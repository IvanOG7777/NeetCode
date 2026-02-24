//
// Created by elder on 2/23/2026.
//


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(const int val) : val(val), next(nullptr) {}
    ListNode(const int val, ListNode *next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto *current = head;
        ListNode *prev = nullptr;

        while (current != nullptr) {
            auto *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};


#include <iostream>

int main() {
    Solution solution;
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(0);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode *resultNode = solution.reverseList(head);
    auto current = resultNode;

    while (current != nullptr) {
        std:: cout << current->val << " ";
        current = current->next;
    }



    delete head;
    delete node2;
    delete node3;
    delete node4;
    return 0;
}