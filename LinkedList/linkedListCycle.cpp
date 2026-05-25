//
// Created by elder on 5/24/2026.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        if (head->next == nullptr) return false;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast) {
            if (fast->next == nullptr) return false;
            if (fast->next->next == nullptr) return false;
            fast = fast->next->next;
            slow = slow->next;
        }

        return true;
    }
};

int main() {
    Solution solution;

    ListNode *head = new ListNode(1);
    ListNode *secondVal = new ListNode(2);
    ListNode *thirdVal = new ListNode(3);
    ListNode *tail = new ListNode(4);

    head->next = secondVal;
    secondVal->next = thirdVal;
    thirdVal->next = tail;
    tail->next = nullptr;

    std:: cout << "Is there a cycle in this list: " << (solution.hasCycle(head) ? "True" : "False") << std:: endl;

    delete head;
    delete secondVal;
    delete thirdVal;
    delete tail;

}