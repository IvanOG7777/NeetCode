//
// Created by elder on 5/25/2026.
//

#include <algorithm>
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) return {};
        if (head->next == nullptr) return {};

        ListNode *newHead{};
        ListNode dummy(-1);
        dummy.next = head;

        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        int counter = 0;

        while (counter < n) {
            fast = fast->next;
            counter++;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *nodeToDelete = slow->next;
        ListNode *afterSlow = nodeToDelete->next;
        ListNode *current = dummy.next;

        while (current != nodeToDelete) {
            current = current->next;
        }

        slow->next = afterSlow;

        newHead = dummy.next;

        return newHead;
    }
};

int main() {

    Solution s;
    ListNode head(1);
    ListNode two(2);
    ListNode three(3);
    ListNode tail(4);

    head.next = &two;
    two.next = &three;
    three.next = &tail;

    ListNode *newH = s.removeNthFromEnd(&head, 2);

    ListNode *current = newH;
    while (current != nullptr) {
        std:: cout << current->val << " ";
        current = current->next;
    }
    std:: cout << std:: endl;

    ListNode head2(5);
    ListNode *newHead2 = s.removeNthFromEnd(&head2, 1);
    ListNode *current2 = newHead2;
    while (current2 != nullptr) {
        std:: cout << current2->val << " ";
        current2 = current2->next;
    }
    std:: cout << std:: endl;

    ListNode head3(1);
    ListNode tail2(2);
    head3.next = &tail2;

    ListNode *newHead3 = s.removeNthFromEnd(&head3, 2);
    ListNode *current3 = newHead3;
    while (current3 != nullptr) {
        std:: cout << current3->val << " ";
        current3 = current3->next;
    }

    return 0;
}