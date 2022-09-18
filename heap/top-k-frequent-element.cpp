// https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i:nums) m[i]++;
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(auto it:m) {
            min_heap.push({it.second, it.first});
            if(min_heap.size() > k) min_heap.pop(); // pop the top
        }

        vector<int>res;
        while(k--) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};

// O(nlogk)