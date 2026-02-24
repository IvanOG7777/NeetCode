//
// Created by elder on 2/23/2026.
//

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


#include <iostream>

class Solution {
private:
    ListNode *reverseListHelper(ListNode *current, ListNode *prev) {
        if (current == nullptr) return prev;

        auto *next = current->next;
        current->next = prev;
        prev = current;

        prev = reverseListHelper(next, prev);

        return prev;
    }
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;

        auto returnValue =  reverseListHelper(head, prev);

        return returnValue;
    }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(0);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    auto current = head;

    while (current != nullptr) {
        std:: cout << current->val << " ";
        current = current->next;
    }

    auto newCurrent = solution.reverseList(head);
    std:: cout << std:: endl;

    while (newCurrent != nullptr) {
        std:: cout << newCurrent->val << " ";
        newCurrent = newCurrent->next;
    }



    delete head;
    delete node2;
    delete node3;
    delete node4;
    return 0;
}