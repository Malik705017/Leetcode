// https://leetcode.com/problems/last-stone-weight

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap(stones.begin(),stones.end());
        
        while(max_heap.size() > 1)
        {
            int y = max_heap.top();
            max_heap.pop();
            int x = max_heap.top();
            max_heap.pop();
            
            if(x != y)
                max_heap.push(y-x);
        }
        
        return !max_heap.empty() ? max_heap.top() : 0; 
    }
};