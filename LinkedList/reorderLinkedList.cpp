//
// Created by elder on 5/25/2026.
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
    void reorderList(ListNode *head) {
        if (head == nullptr) return;
        if (head->next == nullptr) return;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr) {
            if (fast->next == nullptr) break;
            if (fast->next->next == nullptr) break;
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *l2 = slow->next;
        slow->next = nullptr;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        ListNode *current = l2;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        ListNode *l1Current = head;
        ListNode *l2Current = prev;

        while (l1Current != nullptr && l2Current != nullptr) {
            ListNode *l1Next = l1Current->next;
            l1Current->next = l2Current;
            l2Current = l1Next;
            l1Current = l1Current->next;
        }
    }
};

int main() {

    Solution s;
    ListNode two(2);
    ListNode four(4);
    ListNode six(6);
    ListNode eight(8);
    // ListNode ten(10);

    two.next = &four;
    four.next = &six;
    six.next = &eight;
    // eight.next = &ten;

    s.reorderList(&two);

    ListNode *current = &two;
    while (current != nullptr) {
        std:: cout << current->val << " ";
        current = current->next;
    }


    return 0;
}