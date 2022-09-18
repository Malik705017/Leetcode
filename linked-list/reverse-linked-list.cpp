// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* cur = head;
        
        while(cur) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};