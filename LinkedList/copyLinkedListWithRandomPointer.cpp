//
// Created by elder on 5/25/2026.
//

#include <iostream>
#include <unordered_map>
#include <pstl/parallel_impl.h>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        std:: unordered_map<Node*, Node*> nodeMap;

        Node *newHead = new Node(-1);
        Node *current = head;

        while (current != nullptr) {
            nodeMap[current] = new Node(current->val);
            current = current->next;
        }

        for (auto &pair : nodeMap) {
            if (nodeMap[pair.first] == nullptr) {
                pair.second = nullptr;
            } else {
                pair.second->next = nodeMap[pair.first->next];
                pair.second->random = nodeMap[pair.first->random];
            }
        }

        newHead = nodeMap[head];

        return newHead;
    }
};

int main() {

    Solution s;
    Node one(1);
    Node two(2);
    Node three(3);

    one.next = &two;

    two.next = &three;
    two.random = &three;

    three.random = &three;

    Node *newHead = s.copyRandomList(&one);
    Node *current = newHead;

    while (current != nullptr) {
        std:: cout << "Node val: " << current->val << std:: endl;
        std:: cout << "next: " << (current->next == nullptr ? "nullptr" : std::to_string(current->next->val)) << std:: endl;
        std:: cout << "random: " << (current->random == nullptr ? "nullptr" : std::to_string(current->random->val)) << std:: endl;
        std:: cout << std:: endl;
        current = current->next;
    }

    current = nullptr;

    std:: cout << std:: endl;
    std:: cout << std:: endl;


    Node newThree(3);
    Node seven(7);
    Node four(4);
    Node five(5);

    newThree.next = &seven;

    seven.next = &four;
    seven.random = &five;

    four.next = &five;
    four.random = &newThree;

    five.random = &seven;

    Node *case1 = s.copyRandomList(&newThree);
    current = case1;

    while (current != nullptr) {
        std:: cout << "Node val: " << current->val << std:: endl;
        std:: cout << "next: " << (current->next == nullptr ? "nullptr" : std::to_string(current->next->val)) << std:: endl;
        std:: cout << "random: " << (current->random == nullptr ? "nullptr" : std::to_string(current->random->val)) << std:: endl;
        std:: cout << std:: endl;
        current = current->next;
    }



    delete newHead;
    return 0;
}