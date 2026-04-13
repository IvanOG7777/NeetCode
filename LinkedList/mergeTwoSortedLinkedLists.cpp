//
// Created by elder on 2/23/2026.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int val) : val(val), next(nullptr) {
    }

    ListNode(int val, ListNode *next) : val(val), next(next) {
    }
};

ListNode *merge(ListNode *head1, ListNode *head2) {
    if (head1 == nullptr && head2 == nullptr) return {};
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    ListNode *newHead = nullptr;
    ListNode *tail = nullptr;

    ListNode *current1 = head1;
    ListNode *current2 = head2;

    while (current1 != nullptr && current2 != nullptr) {
        if (newHead == nullptr) {
            if (current1->val == current2->val) {
                newHead = current1;
                tail = newHead;
                current1 = current1->next;
            } else if (current1->val < current2->val) {
                newHead = current1;
                tail = newHead;
                current1 = current1->next;
            } else {
                newHead = current2;
                tail = newHead;
                current2 = current2->next;
            }
        } else {
            if (current1->val == current2->val) {
                tail->next = current1;
                tail = tail->next;
                current1 = current1->next;
            } else if (current1->val < current2->val) {
                tail->next = current1;
                tail = tail->next;
                current1 = current1->next;
            } else {
                tail->next = current2;
                tail = tail->next;
                current2 = current2->next;
            }
        }
    }

    if (current1 != nullptr) {
        tail->next = current1;
    }

    if (current2 != nullptr) {
        tail->next = current2;
    }

    return newHead;
}

int main() {
<<<<<<< Updated upstream

    ListNode *head1 = new ListNode(1);
    ListNode *head1Node1 = new ListNode(2);
    ListNode *head1Node2 = new ListNode(4);

    ListNode *head2 = new ListNode(1);
    ListNode *head2Node1 = new ListNode(3);
    ListNode *head2Node2 = new ListNode(5);

    auto l1 = head1;
    auto l2 = head2;

    ListNode *dummy = nullptr;


=======
    ListNode head(1);
    ListNode hNode1(2);
    ListNode hNode2(4);
    head.next = &hNode1;
    hNode1.next = &hNode2;

    ListNode head2(1);
    ListNode hNode3(3);
    ListNode hNode4(5);
    head2.next = &hNode3;
    hNode3.next = &hNode4;

    ListNode *current1 = &head;
    ListNode *current2 = &head2;
    while (current1 != nullptr) {
        printf("%d ", current1->val);
        current1 = current1->next;
    }
    printf("\n");
    while (current2 != nullptr) {
        printf("%d ", current2->val);
        current2 = current2->next;
    }
    printf("\n");
    ListNode *newHead = merge(&head, &head2);
    ListNode *newCurrent = newHead;
    while (newCurrent != nullptr) {
        printf("%d ", newCurrent->val);
        newCurrent = newCurrent->next;
    }
>>>>>>> Stashed changes
    return 0;
}
