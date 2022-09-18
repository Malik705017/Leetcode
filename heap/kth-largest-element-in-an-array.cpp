// https://leetcode.com/problems/kth-largest-element-in-an-array

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int num : nums) { // O(n)
            min_heap.push(num); // O(logk)
            if (min_heap.size() > k) {
                min_heap.pop(); // O(1) + O(logk)
            }
        }
        return min_heap.top();
    }
};

// O(nlogk)