// https://leetcode.com/problems/linked-list-cycle-ii/
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head -> next) return NULL;
        
        ListNode* oneStepPtr = head;
        ListNode* twoStepPtr = head;
        bool isCycle = false;
        
        while (oneStepPtr && twoStepPtr) {
            oneStepPtr = oneStepPtr -> next;
            
            if(!twoStepPtr -> next) {
                return NULL;
            }
           
            twoStepPtr = twoStepPtr -> next -> next;
                
            if (oneStepPtr == twoStepPtr) {
                isCycle = true;
                break;
            }
        }
        
        if(!isCycle) return NULL;
        
        twoStepPtr = head;
        
        while (twoStepPtr != oneStepPtr) {
            oneStepPtr = oneStepPtr -> next;
            twoStepPtr = twoStepPtr -> next;
        }
        
        return oneStepPtr;
    }
};