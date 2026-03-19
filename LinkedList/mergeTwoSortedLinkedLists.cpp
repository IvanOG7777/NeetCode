//
// Created by elder on 2/23/2026.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

int main() {

    ListNode *head1 = new ListNode(1);
    ListNode *head1Node1 = new ListNode(2);
    ListNode *head1Node2 = new ListNode(4);

    ListNode *head2 = new ListNode(1);
    ListNode *head2Node1 = new ListNode(3);
    ListNode *head2Node2 = new ListNode(5);

    auto l1 = head1;
    auto l2 = head2;

    ListNode *dummy = nullptr;


    return 0;
}